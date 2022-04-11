#ifndef Log_H
#define Log_H

#include "CurrentThread.h"
#include "LogEventWarp.h"
#include "LogManager.h"
#include "LogLevel.h"
#define LOG_ROOT() afa::LogManager::GetInstance()->GetRoot()

#define LOG_NAME(name) afa::LogManager::GetInstance()->GetLog(name)

//流式输出
#define LOG_LEVEL(logger,level) \
    if(logger->GetLevel()<=level) \
         afa::LogEventWarp(logger,afa::LogEvent::ptr(new afa::LogEvent(level, \
        __FILE__,__LINE__,afa::CurrentThread::tid(),\
        0,time(0),std::string(afa::CurrentThread::name())))).GetSS()

#define LOG_DEBUG(logger) LOG_LEVEL(logger,afa::LogLevel::DEBUG)

#define LOG_INFO(logger) LOG_LEVEL(logger,afa::LogLevel::INFO)

#define LOG_WARN(logger) LOG_LEVEL(logger,afa::LogLevel::WARN)

#define LOG_ERROR(logger) LOG_LEVEL(logger,afa::LogLevel::ERROR)

#define LOG_FATAL(logger) LOG_LEVEL(logger,afa::LogLevel::FATAL)



#define LOG_FMT_LEVEL(logger,level,fmt,...) \
    if(logger->GetLevel()<=level) \
        afa::LogEventWarp(logger,afa::LogEvent::ptr(new afa::LogEvent(level, \
        __FILE__,__LINE__,afa::CurrentThread::tid(), \
        0,time(0),std::string(afa::CurrentThread::name())) \
        ).format(fmt,__VA_ARGS__); 






#define LOG_FMT_DEBUG(logger,fmt,...)  LOG_FMT_LEVEL(logger,afa::LogLevel::DEBUG,fmt, __VA_ARGS__)

#define LOG_FMT_INFO(logger,fmt,...)  LOG_FMT_LEVEL(logger,afa::LogLevel::INFO,fmt, __VA_ARGS__)

#define LOG_FMT_WARN(logger,fmt,...)  LOG_FMT_LEVEL(logger,afa::LogLevel::WARN,fmt, __VA_ARGS__)

#define LOG_FMT_ERROR(logger,fmt,...)  LOG_FMT_LEVEL(logger,afa::LogLevel::ERROR,fmt, __VA_ARGS__)

#define LOG_FMT_FATAL(logger,fmt,...)  LOG_FMT_LEVEL(logger,afa::LogLevel::FATAL,fmt, __VA_ARGS__)




#endif
    