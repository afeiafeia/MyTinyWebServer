#ifndef LOG_APPENDER_H
#define LOG_APPENDER_H
#include <memory>
#include "LogLevel.h"
#include "LogFormatter.h"
namespace afa
{
    class LogAppender
    {
    public:
        typedef std::shared_ptr<LogAppender> ptr;
    private:
        LogLevel::Level m_level;
        std::shared_ptr<LogFormatter> m_spFormatter;

    public:
        LogAppender()
        :m_level(LogLevel::DEBUG)
        ,m_spFormatter(new LogFormatter())
        {

        }
        virtual ~LogAppender(){}

        LogFormatter::ptr GetFormatter()
        {
            return m_spFormatter;
        }
        void SetFormatter(LogFormatter::ptr spFormatter)
        {
            m_spFormatter = spFormatter;
        }

        LogLevel::Level GetLevel()
        {
            return m_level;
        }
        void SetLevel(LogLevel::Level level)
        {
            m_level = level;
        }

        virtual void Log(LogLevel::Level level,LogEvent::ptr event)=0;
    };
}


#endif