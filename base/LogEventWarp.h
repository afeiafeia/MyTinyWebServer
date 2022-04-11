#ifndef LOG_EVENT_WARP_H
#define LOG_EVENT_WARP_H
#include <memory>
#include "LogEvent.h"
#include "Logger.h"
namespace afa
{
    class LogEventWarp
    {
    public:
        typedef std::shared_ptr<LogEventWarp> ptr;

    private:
        LogEvent::ptr m_event;
        Logger::ptr   m_logger;
    public:
        LogEventWarp(Logger::ptr logger,LogEvent::ptr event);

        ~LogEventWarp();

        std::stringstream& GetSS(){return m_event->GetSS();}
    };
}



#endif