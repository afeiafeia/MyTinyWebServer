#ifndef LOGGER_H
#define LOGGER_H

#include "noncopyable.h"
#include <string>
#include <list>
#include "LogFile.h"
#include "LogLevel.h"
#include "LogAppender.h"
#include "LogEvent.h"
#include "MutexLock.h"
#include "MutexLockGuard.h"
#include <memory>
namespace afa
{

    class LogAppender;
    class LogEvent;
    class Logger: public std::enable_shared_from_this<Logger>
    {
    public:
        typedef std::shared_ptr<Logger>  ptr;
        typedef LogLevel::Level level;
    private:
        std::string                   m_name;      //日志名称
        LogLevel::Level               m_level;     //日志级别
        std::list<LogFile::ptr>       m_appenders; //日志输出器
        std::list<LogAppender::ptr>   m_vctAppenders; //日志输出器
        MutexLock                     m_lock;

    public:
        Logger(const std::string &name,level logLevel=LogLevel::DEBUG);
        ~Logger();

        void AddAppender(LogFile::ptr& addAppender);

        void AddAppender(LogAppender::ptr addAppender);

        void DelAppender(LogFile::ptr& delAppender);

        void Log(const char* logLine,int len);

        void Log(const std::string &s,LogLevel::Level level);

        void Log(LogLevel::Level level,LogEvent::ptr event);

        void Debug(LogEvent::ptr event);        


        LogLevel::Level GetLevel()
        {
            return m_level;
        }

    private:
        LogEvent::ptr ConstructLogEvent(const std::string &content,LogLevel::Level level);

    };
}
#endif
