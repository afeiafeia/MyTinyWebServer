#ifndef MY_TINY_WEB_LOG_H
#define MY_TINY_WEB_LOG_H
#include "../lock/locker.h"
#include <bits/types/FILE.h>
#include "block_queue.h"
class log
{
private:
    //static log* m_log;
    char m_dir_name[128];
    char m_log_name[128];   //日志文件名称
    int m_split_lines;    //每个日志的最大行数，超过此行数，新创建一个日志文件
    int m_log_buf_size;   //存放每行日志信息的缓冲区的最大空间
    long long m_count;    //当前日志的行数
    int m_today;
    FILE* m_fp;
    char* m_buf;          //日志信息的缓冲区
    bool m_is_async;      //是否异步写入
    locker m_lock;
    int m_close_log;

    block_queue<string>::pointer m_pBlockQueue;  //阻塞队列


public:
    static log* GetInstance();

    static void* Flush_Log_Thread(void* arg)
    {
        log::GetInstance()->Async_Write_Log();
    }

    bool Init(const char* file_name,int close_flag,int log_buf_size=8192,int solit_lines = 5000000,int max_queue_size = 0);

    bool Write_Log(int level,const char* format,...);

    void Flush(void);
private:
    log();
    virtual ~log();

    void Async_Write_Log();




};


#define LOG_DEBUG(format, ...) if(0 == m_close_log){ \
    log::GetInstance()->Write_Log(0, format, ##__VA_ARGS__); \
    log::GetInstance()->Flush();}
#define LOG_INFO(format, ...) if(0 == m_close_log){log::GetInstance()->Write_Log(1, format, ##__VA_ARGS__); log::GetInstance()->Flush();}
#define LOG_WARN(format, ...) if(0 == m_close_log){log::GetInstance()->Write_Log(2, format, ##__VA_ARGS__); log::GetInstance()->Flush();}
#define LOG_ERROR(format, ...) if(0 == m_close_log){log::GetInstance()->Write_Log(3, format, ##__VA_ARGS__); log::GetInstance()->Flush();}

#endif
