#ifndef LOG_EVENT_H
#define LOG_EVENT_H
#include <sstream>
#include <string>
#include <memory>
#include "LogLevel.h"
namespace afa
{
    class Logger;
    class LogEvent
    {
    public:
        typedef std::shared_ptr<LogEvent> ptr;
        typedef std::shared_ptr<Logger> LogPtr;
    private:
        std::shared_ptr<Logger> m_shLogger; //日志器
        LogLevel::Level m_level; //日志级别
        std::string m_fileName;  //日志语句所在文件，通过__FILE__宏得到
        u_int32_t m_line;//行号
        u_int32_t m_threadId;        //线程id
        u_int32_t m_fiberId;         //协程id
        u_int64_t m_time;            //时间
        std::string m_threadName;    //线程名称
        std::string m_content;
        std::stringstream m_contentStream;

    public:
        LogEvent(LogLevel::Level level,
                std::string     fileName,
                u_int32_t       line,
                u_int32_t       threadId,
                u_int32_t       fiberId,
                u_int64_t       time,
                std::string     threadName);

        ~LogEvent();

        /**
         * @brief  获取日志器
         * @author afei
         * @date   2022-03-25
         * @return LoggerPtr 
         */
        LogPtr GetLogger(){return m_shLogger;}

        /**
         * @brief  获取日志级别
         * @author afei
         * @date   2022-03-25
         * @return LogLevel::Level 
         */
        LogLevel::Level GetLogLevel(){return m_level;}

        /**
         * @brief  获取创建日志的文件的文件名称
         * @author afei
         * @date   2022-03-25
         * @return std::string 
         */
        std::string GetFileName(){return m_fileName;}

        /**
         * @brief  获取行号
         * @author afei
         * @date   2022-03-25
         * @return u_int32_t 
         */
        u_int32_t GetLine(){return m_line;}

        /**
         * @brief  获取日志的创建时间
         * @author afei
         * @date   2022-03-25
         * @return u_int64_t 
         */
        u_int64_t GetTime(){return m_time;}

        /**
         * @brief  获取创建日志的线程的id
         * @author afei
         * @date   2022-03-25
         * @return u_int32_t 
         */
        u_int32_t GetThreadId(){return m_threadId;}

        /**
         * @brief  获取创建日志的协程的id
         * @author afei
         * @date   2022-03-25
         * @return u_int32_t 
         */
        u_int32_t GetFiberId(){return m_fiberId;}

        /**
         * @brief  获取创建日志的线程的名称
         * @author afei
         * @date   2022-03-25
         * @return std::string 
         */
        std::string GetThreadName(){return m_threadName;}

        /**
         * @brief  获取日志内容
         * @author afei
         * @date   2022-03-25
         * @return std::string 
         */
        std::string GetContent(){return m_contentStream.str();}

        std::stringstream& GetSS(){return m_contentStream;}

        /**
         * @brief  格式化写入日志内容
         * @author afei
         * @date   2022-03-25
         */
        void format(const char* formatContent,...);

        /**
         * @brief  格式化写入日志内容
         * @param  formatContent    
         * @param  va               
         * @author afei
         * @date   2022-03-25
         */
        void format(const char* formatContent,va_list va);

    };
}
#endif