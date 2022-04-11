#ifndef LOG_FILE_H
#define LOG_FILE_H

#include "FileUtil.h"
#include "noncopyable.h"
#include <bits/unique_ptr.h>
#include "MutexLock.h"
#include <memory>
namespace afa
{
    class LogFile:public noncopyable
    {
    public:
        typedef std::shared_ptr<LogFile> ptr;
    private:
        const std::string m_filePath;
        const int m_periodic;
        std::unique_ptr<FileUtil> m_file;
        std::unique_ptr<MutexLock> m_lock;
        int m_count;
    public:
        /**
         * @brief  Construct a new Log File object
         * @param  filePath         
         * @param  periodic         
         * @author afei (1763029328@qq.com)
         * @date   2022-03-25
         */
        LogFile(const std::string &filePath,int periodic=10);

        /**
         * @brief  Destroy the Log File object
         * @author afei (1763029328@qq.com)
         * @date   2022-03-25
         */
        ~LogFile();

        /**
         * @brief  向文件写入数据
         * @param  logLine          
         * @param  len              
         * @author afei
         * @date   2022-03-25
         */
        void Append(const char* logLine,size_t len);

        /**
         * @brief  刷新缓冲区
         * @author afei
         * @date   2022-03-25
         */
        void Flush();
    private:
        /**
         * @brief  向文件写入数据（供Append函数调用）
         * @param  logLine          
         * @param  len              
         * @author afei
         * @date   2022-03-25
         */
        void AppendLogData(const char* logLine,size_t len);


    };
}
#endif