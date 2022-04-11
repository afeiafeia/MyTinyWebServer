#include "LogEvent.h"
#include <stdarg.h>
namespace afa
{

    LogEvent::LogEvent(
        LogLevel::Level level,
        std::string     fileName,
        u_int32_t       line,
        u_int32_t       threadId,
        u_int32_t       fiberId,
        u_int64_t       time,
        std::string     threadName)
        :m_level(level)
        ,m_fileName(fileName)
        ,m_line(line)
        ,m_threadId(threadId)
        ,m_fiberId(fiberId)
        ,m_time(time)
        ,m_threadName(threadName)
        {
            int i=0;
            int j=i+1;
        }

        LogEvent::~LogEvent()
        {

        }

    void LogEvent::format(const char* formatContent,...)
    {
        va_list al;
        va_start(al,formatContent);
        format(formatContent,al);
        va_end(al);
    }

    void LogEvent::format(const char* formatContent,va_list va)
    {
        char* buff = nullptr;
        int len = vasprintf(&buff,formatContent,va);
        if(len>0)
        {
            m_content = std::move(std::string(buff));
            free(buff);
        }
    }
}