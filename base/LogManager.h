#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H
#include "Logger.h"
#include <map>
namespace afa
{
    class LogManager
    {
    private:
        Logger::ptr m_root;
        std::map<std::string,Logger::ptr> m_logger;
    private:
        LogManager()
        :m_root(new Logger("root"))
        {
            m_logger["root"] = m_root;
        }
        ~LogManager(){};
        
    public:
        static LogManager* GetInstance()
        {
            static LogManager singleTon;
            return &singleTon;
        }

        Logger::ptr GetRoot()
        {
            return m_root;
        }

        Logger::ptr GetLog(const std::string &s)
        {
            if(m_logger.find(s)==m_logger.end())
            {
                m_logger[s] = Logger::ptr(new Logger(s));
            }
            return m_logger[s];
        }


    };

}

#endif