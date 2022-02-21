#include "log.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
log::log()
{
    m_count=0;
    m_is_async = false;
}
log::~log()
{
    if(m_fp!=nullptr)
    {
        fclose(m_fp);
    }
}

log* log::GetInstance()
{
    static log SingleTonLog;
    return &SingleTonLog;
}

bool log::Init(const char* file_name,int close_flag,int log_buf_size,int split_lines,int max_queue_size)
{
    if(max_queue_size>0)
    {
        m_is_async = true;
        m_pBlockQueue = new block_queue<string> (max_queue_size);
        pthread_t tid;
        pthread_create(&tid,NULL,Flush_Log_Thread,NULL);
    }
    m_close_log = close_flag;
    m_log_buf_size = log_buf_size;
    m_split_lines = split_lines;
    m_buf = new char[m_log_buf_size];
    memset(m_buf,'\0',m_log_buf_size);

    time_t t = time(NULL);
    struct tm* sys_time = localtime(&t);

    struct tm curTime = *sys_time;
    
    //char* strrchr(const char* str,int c);
    //在str所指的字符串中中搜索最后一次出现字符c的位置
    const char* p = strrchr(file_name,'/');
    char log_full_name[256] = {0};
    if(p==nullptr)
    {
        snprintf(log_full_name,256,"%d_%02d_%02d_%s",curTime.tm_year+1900,curTime.tm_mon+1,curTime.tm_mday,file_name);
    }
    else
    {
        strcpy(m_log_name,p+1);
        strncpy(m_dir_name,file_name,p-file_name+1);
        snprintf(log_full_name,256,"%s%d_%02d_%02d_%s",m_dir_name,curTime.tm_year+1900,curTime.tm_mon+1,curTime.tm_mday,m_log_name);
    }

    m_today = curTime.tm_mday;
    m_fp = fopen(log_full_name,"a");
    if(m_fp==nullptr)
    {
        return false;
    }

    return true;
}


void log::Flush()
{
    m_lock.Lock();
    //fflush冲刷缓冲区，将流缓冲区中的数据排入磁盘或者终端的写队列
    fflush(m_fp);
    m_lock.UnLock();
}


void log::Async_Write_Log()
{
    string curLog;
    //这里pop的时候没有加锁，是因为阻塞队列中已经加了锁
    //当然，因为只有一个异步写线程，写入的时候不加锁也可以，但多线程时，就需要加锁的
    while(m_pBlockQueue->pop(curLog))
    {
        m_lock.Lock();
        fputs(curLog.c_str(),m_fp);
        m_lock.UnLock();
    }

    //局部变量的定义可以放在锁外面，不需要加锁（线程间不共享），减小临界区大小（也称为：减小锁（同步）的粒度）
}


bool log::Write_Log(int level,const char* format,...)
{
    //struct timeval curTime;
    //gettimeofday(&curTime,NULL);

    time_t cur = time(NULL);
    struct tm* curSys_Time = localtime(&cur);
    struct tm nowDay = *curSys_Time;
    char s[16] = {'\0'};
    switch(level)
    {
    case 0:
        sprintf(s,"[debug]:");
        break;
    case 1:
        sprintf(s,"[info]:");
        break;
    case 2:
        sprintf(s,"[warning]:");
        break;
    case 3:
        sprintf(s,"[error]:");
        break;
    default:
        sprintf(s,"[info]:");
        break;
    }
    m_lock.Lock();
    m_count++;
    if(m_today!=nowDay.tm_mday||m_count%m_split_lines==0)
    {
        fflush(m_fp);
        fclose(m_fp);
        char newLogName[256] = {'\0'};
        char tail[16] = {'\0'};
        snprintf(tail,16,"%d_%02d_%02d_",nowDay.tm_year+1900,nowDay.tm_mon+1,nowDay.tm_mday);
        if(m_today!=nowDay.tm_mday)
        {
            snprintf(newLogName,256,"%s%s",tail,m_log_name);
            m_count=0;
            m_today = nowDay.tm_mday;
        }
        else
        {
            snprintf(newLogName,256,"%s%lld",tail,m_count/m_split_lines);
        }
        m_fp = fopen(newLogName,"a");
    }
    m_lock.UnLock();

    string logInfor;
    va_list valist;
    va_start(valist,format);
    m_lock.Lock();

    int n = snprintf(m_buf,48,"%d-%02d-%02d %02d:%02d:%02d %s",
                        nowDay.tm_year+1900,nowDay.tm_mon+1,nowDay.tm_mday,
                        nowDay.tm_hour,nowDay.tm_min,nowDay.tm_sec,s);

    int m = vsnprintf(m_buf+n,m_log_buf_size-1,format,valist);
    m_buf[n+m] = '\n';
    m_buf[n+m+1] = '\0';
    logInfor = m_buf;
    m_lock.UnLock();

    if(m_is_async&&!m_pBlockQueue->full())
    {
        m_pBlockQueue->push(logInfor);
    }
    else
    {
        m_lock.Lock();
        fputs(logInfor.c_str(),m_fp);
        m_lock.UnLock();
    }

    va_end(valist);

    return true;


}