#include "FileUtil.h"
#include <stdio.h>
namespace afa
{
    FileUtil::FileUtil(std::string filePath)
    :m_File(fopen(filePath.c_str(),"a"))
    {
        setbuffer(m_File,m_buffer,sizeof(m_buffer));
    }

    FileUtil::~FileUtil()
    {
        fclose(m_File);
    }

    void FileUtil::Append(const char* logLine,size_t len)
    {
        size_t writeNum = fwrite(logLine,1,len,m_File);
        size_t remain = len-writeNum;
        while(remain>0)
        {
            size_t x = fwrite(logLine+writeNum,remain,1,m_File);
            if(x==0)
            {
                int err = ferror(m_File);
                if(err)
                {
                    fprintf(stderr,"Append Filed!\n");
                    break;
                }
            }
            writeNum+=x; 
            remain-=x;
        }
    }
    void FileUtil::Flush()
    {
        fflush(m_File);
        
    }
}