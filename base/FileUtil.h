 
 #ifndef FILE_UTIL_H
 #define FILE_UTIL_H

 #include "noncopyable.h"
 #include <string>
 namespace afa
 {
     class FileUtil:public noncopyable
     {
     private:
        FILE* m_File;
        char m_buffer[64*1024];
     public: 
        explicit FileUtil(std::string filePath);
        ~FileUtil();

        void Append(const char* logLine,size_t len);
        void Flush();

     };
 }

 #endif