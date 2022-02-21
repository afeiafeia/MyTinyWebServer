#ifndef MY_TINY_WEB_SQL_CONNECTION_POOL_H
#define MY_TINY_WEB_SQL_CONNECTION_POOL_H
#include <string>
#include "../lock/locker.h"
#include "../lock/sem.h"
#include <list>
#include <mysql/mysql.h>
using namespace std;

class connection_pool
{
private:
    static connection_pool* m_sInstance;

    std::string m_url;            //主机地址
    unsigned int m_port;           //数据库端口
    std::string m_User;           //登录数据库的用户名
    std::string m_Password;       //登录数据库密码
    std::string m_DataBaseName;   //使用的数据库名称
    int m_close_log;              //日志开关

    int m_MaxConn;                //最大连接数
    int m_CurConn;                //目前已经使用的连接数
    int m_FreeConn;               //当前空闲的连接数
    locker m_lock;                //锁
    sem    m_sem;                 //信号量，初始化为最大连接数
    std::list<MYSQL*> m_listMYSQL; //连接池


public:
    connection_pool();

    ~connection_pool();

    static connection_pool* GetInstance();

    void init(
        const string &iUrl,
        const string &iUser,
        const string &iPassword,
        const string &iDataBase,
        const int     iPort=3306,
        const unsigned     iMaxConn = 100,
        int m_close_log =0);

    MYSQL* GetConnection();

    bool ReleaseConnection(MYSQL* pCurConn);


    void DestroyConnectionPool();



};
#endif