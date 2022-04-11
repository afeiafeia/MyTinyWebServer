#include "Logger.h"
#include "FileLogAppender.h"
#include "CurrentThread.h"
namespace afa
{
    Logger::Logger(const std::string &name,level curLevel)
    :m_name(name)
    ,m_level(curLevel)
    ,m_lock()
    {
        std::shared_ptr<LogFile> spLogFile(new LogFile(name));
        m_appenders.push_back(spLogFile);

        //添加一个文件日志输出器
        LogAppender::ptr fileAppder(new FileLogAppender("./"+m_name+"Log.txt"));
        m_vctAppenders.push_back(fileAppder);
    }
    
    Logger::~Logger()
    {

    }

    void Logger::AddAppender(LogFile::ptr &appender)
    {
        MutexLockGuard guard(&m_lock);
        m_appenders.push_back(appender);
    }

    void Logger::AddAppender(LogAppender::ptr appender)
    {
        MutexLockGuard guard(&m_lock);
        m_vctAppenders.push_back(appender);
    }

    void Logger::DelAppender(LogFile::ptr &delAppe)
    {
        MutexLockGuard guard(&m_lock);
        for(auto it = m_appenders.begin();it!=m_appenders.end();++it)
        {
            if(*it==delAppe)
            {
                m_appenders.erase(it);
                break;
            }
        }
    }

    void Logger::Log(const char* logLine,int len)
    {
        for(auto it = m_appenders.begin();it!=m_appenders.end();++it)
        {
            (*it)->Append(logLine,len);
        }
    }
    void Logger::Log(const std::string &s,LogLevel::Level level)
    {
        LogEvent::ptr curEvent(ConstructLogEvent(s,level));
        Log(level,curEvent);
    }

    void Logger::Log(LogLevel::Level level,LogEvent::ptr event)
    {
        if(level<m_level)
        {
            return;
        }
        int num = m_appenders.size();
        ptr self = shared_from_this();
        for(auto& it:m_vctAppenders)
        {
            it->Log(level,event);
        }
    }

    LogEvent::ptr Logger::ConstructLogEvent(const std::string &content,LogLevel::Level level)
    {
        return LogEvent::ptr(new LogEvent(level,__FILE__,__LINE__,CurrentThread::tid(),0,time(0),CurrentThread::name()));
    }


}