#include "LogFormatter.h"
#include <map>
#include <functional>
namespace afa
{
    LogFormatter::LogFormatter(const std::string &pattern)
    :m_pattern(pattern)
    {
        Init();
    }

    void LogFormatter::Init()
    {
        int n = m_pattern.size();
        std::vector<std::pair<std::string,std::string>> vctItems;
        for(int i=0;i<n;i++)
        {
            std::string preStr;
            if(m_pattern[i]!='%')
            {
                continue;
            }

            int index = i+1;//从一个%的下一个字符开始，i处为%
            std::string curStr;
            std::string formatStr;
            int dateBegin = i+1;
            int status = 0;
            while(index<n)
            {
                if(!status&&!isalpha(m_pattern[index])&&m_pattern[index]!='{'&&m_pattern[index]!='}')
                {
                    //正常格式下，在index处为%时进入
                    //curStr为%前的字符
                    curStr = m_pattern.substr(i+1,index-i-1);
                    break;
                }

                if(!status&&m_pattern[index]=='{')
                {
                    curStr = m_pattern.substr(i+1,index-i-1);
                    status = 1;
                    dateBegin = index+1;
                }
                else if(status&&m_pattern[index]=='}')
                {
                    status = 0;
                    formatStr = m_pattern.substr(dateBegin,index-dateBegin);
                    ++index;
                    break;
                }
                ++index;
                if(index==n)
                {
                    if(curStr.empty())
                    {
                        curStr = m_pattern.substr(i+1);
                        vctItems.push_back({curStr,formatStr});
                    }
                }
            }
            if(!curStr.empty())
            {
                vctItems.push_back({curStr,formatStr});
            }
            i = index-1;//后续++会使得i从%开始
            static std::map<std::string,std::function<LogFormatterItem::ptr(const std::string &s)>> s_format_item = {
#define XX(str,C) \
            {#str,[](const std::string &s){return LogFormatterItem::ptr(new C(s));}}

            XX(m,ContentFormatterItem),   //消息
            XX(p,LevelFormatterItem),     //日志等级
            XX(t,ThreadIdFormatterItem),  //线程Id
            XX(n,NewLineFormatterItem),   //换行
            XX(d,TimeFormatterItem),      //时间
            XX(l,LineFormatterItem),      //行号
            XX(F,FiberIdFormatterItem),   //协程Id
            XX(N,ThreadNameFormatterItem),//线程名称
            XX(f,FileFormatterItem),      //文件名称
            XX(T,TabFormatterItem),       //制表符
#undef XX
            };

            int numItem = vctItems.size();
            for(int i=0;i<numItem;++i)
            {
                std::string name = vctItems[i].first;
                std::string content = vctItems[i].second; 
                if(s_format_item.find(name)!=s_format_item.end())
                {
                    m_vctItems.push_back(s_format_item[name](content));
                }
            }
            vctItems.clear();

            
        }
       
    }

    void LogFormatter::Format(std::ostream &os,LogLevel::Level level,LogEvent::ptr event)
    {
        for(int i=0;i<m_vctItems.size();++i)
        {
            m_vctItems[i]->Format(os,level,event);
        }
    }

    void LogFormatter::SetFormat(const std::string &newPattern)
    {
        m_pattern = newPattern;
        Init();
    }
}