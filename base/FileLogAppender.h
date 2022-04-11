#ifndef FILE_LOG_APPENDER_H
#define FILE_LOG_APPENDER_H
#include <iostream>
#include <fstream>
#include <memory>
#include "Logger.h"
#include "LogEvent.h"
#include "LogLevel.h"
#include "LogAppender.h"
namespace afa
{
    class FileLogAppender:public LogAppender
    {
    public:
        typedef std::shared_ptr<FileLogAppender> ptr;
    private:
        std::ofstream m_fileStream;//文件流
        std::string m_filePath;//文件路径
    public:

        FileLogAppender(const std::string &path);

        void Log(LogLevel::Level level,LogEvent::ptr event);
    private:
        void OpenFile();
    };
}


#endif