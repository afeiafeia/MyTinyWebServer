#include "LogFile.h"
#include "MutexLockGuard.h"
 namespace afa
 {
     LogFile::LogFile(const std::string &fileName,int periodic)
     :m_filePath(fileName)
     ,m_periodic(periodic)
     ,m_file(new FileUtil(fileName))
     ,m_lock(new MutexLock())
     ,m_count(0)
     {

     }

     LogFile::~LogFile()
     {

     }
     void LogFile::Append(const char* logLine,size_t len)
     {
        MutexLockGuard guard(m_lock.get());
        AppendLogData(logLine,len);
     }

     void LogFile::Flush()
     {
        MutexLockGuard guard(m_lock.get());
        m_file->Flush();
     }

     void LogFile::AppendLogData(const char* logLine,size_t len)
     {
        m_file->Append(logLine,len);
        m_count++;
        if(m_count>m_periodic)
        {
           m_file->Flush();
           m_count = 0;
        }
     }

 }