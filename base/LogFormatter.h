#ifndef LOG_FORMATTER_H
#define LOG_FORMATTER_H

#include <memory>
#include <vector>
#include "LogLevel.h"
#include "LogEvent.h"
#include "LogFormatterItem.h"
namespace afa
{
    class LogFormatter
    {
    public:
        typedef std::shared_ptr<LogFormatter> ptr;
        typedef std::shared_ptr<LogFormatterItem> ItemPtr;

        LogFormatter(const std::string& pattern = "%d{%Y-%m-%d %H:%M:%S}%T%t%T%N%T%F%T%p%T%c%T%f%l%T%m%n");

        void Init();

        void Format(std::ostream &os,LogLevel::Level level,LogEvent::ptr event);

        void SetFormat(const std::string &newPattern);

        std::string GetFormat()
        {
            return m_pattern;
        }

    private:
        std::string m_pattern;//日志格式模板
        std::vector<ItemPtr> m_vctItems; //日志输出项
    };
}
#endif