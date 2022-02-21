#include "sql_connection_pool.h"
#include "../log/log.h"
#include <iostream>
connection_pool* connection_pool::m_sInstance = nullptr;

connection_pool::connection_pool()
{

}

connection_pool::~connection_pool()
{

}

connection_pool* connection_pool::GetInstance()
{
    static connection_pool instance;
    return &instance;
}


void connection_pool::init(
        const string           &iUrl,
        const string           &iUser,
        const string           &iPassword,
        const string           &iDataBase,
        const int              iPort,
        const unsigned int     iMaxConn,
        int                    close_log)
{
    m_url          = iUrl;
    m_User         = iUser;
    m_Password     = iPassword;
    m_port         = iPort;
    m_DataBaseName = iDataBase;
    m_MaxConn      = iMaxConn;
    m_close_log    = close_log;

    for(int i=0;i<m_MaxConn;i++)
    {
        MYSQL* pMysql = nullptr;
        pMysql = mysql_init(pMysql);
        if(pMysql==nullptr)
        {
            //std::cout<<"Error:"<<mysql_error(pMysql);
            LOG_ERROR("%s","Failed To Init MYSQL!");
            exit(0);
        }
        pMysql = mysql_real_connect(pMysql,m_url.c_str(),m_User.c_str(),m_Password.c_str(),m_DataBaseName.c_str(),m_port,NULL,0);
        if(pMysql==nullptr)
        {
            std::cout<<"Error:"<<mysql_error(pMysql);
        }

        m_listMYSQL.push_back(pMysql);
        m_FreeConn++;
    }
    m_sem = sem(m_FreeConn);
    m_MaxConn = m_FreeConn;         
}


MYSQL* connection_pool::GetConnection()
{
    if(m_listMYSQL.empty())
    {
        return nullptr;
    }
    MYSQL* pCurConn = nullptr;
    m_sem.Wait();
    m_lock.Lock();//锁用来保护链表
    pCurConn = m_listMYSQL.front();
    m_listMYSQL.pop_front();
    m_FreeConn--;
    m_CurConn++;
    m_lock.UnLock();
    return pCurConn;
}

bool connection_pool::ReleaseConnection(MYSQL* iCurConn)
{
    if(iCurConn==nullptr)
    {
        return false;
    }
    m_lock.Lock();
    m_listMYSQL.push_back(iCurConn);
    m_FreeConn++;
    m_CurConn--;
    m_lock.UnLock();
    m_sem.Post();
    return true;
}

void connection_pool::DestroyConnectionPool()
{
    m_lock.Lock();
    if(!m_listMYSQL.empty())
    {
        list<MYSQL*>::iterator it;
        for(it = m_listMYSQL.begin();it!=m_listMYSQL.end();it++)
        {
            MYSQL* cur = *it;
            mysql_close(cur);
        }
        m_CurConn=0;
        m_FreeConn = 0;
        m_listMYSQL.clear();
    }
    m_lock.UnLock();
}