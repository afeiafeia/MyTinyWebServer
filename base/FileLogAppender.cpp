#include "FileLogAppender.h"
namespace afa
{
    FileLogAppender::FileLogAppender(const std::string &path)
    :m_filePath(path)
    {
        OpenFile();
    }

    void FileLogAppender::Log(LogLevel::Level level,LogEvent::ptr event)
    {
        GetFormatter()->Format(m_fileStream,level,event);
    }

    void FileLogAppender::OpenFile()
    {
        if(m_fileStream)
        {
            m_fileStream.close();
        }
        m_fileStream.open(m_filePath.c_str(), std::ios::app);   

    }
}