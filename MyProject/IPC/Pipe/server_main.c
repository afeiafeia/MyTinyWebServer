#include "fifo.h"

#include "unpipc.h"

int main(int argc,char** argv)
{
    int readfd;
    int writefd;
//while(TRUE)
//{    
    if(mkfifo(FIFO1,FILE_MODE)<0&&errno!=EEXIST)
    {
        err_sys("Create Fifo Failed!");
    }

    if (mkfifo(FIFO2,FILE_MODE)<0&&errno!=EEXIST)
    {
        err_sys("Create Fifo Failed!");        /* code */
    }

    readfd = open(FIFO1,O_RDONLY,0);
    writefd =open(FIFO2,O_WRONLY,0);
    server(readfd,writefd);

    //exit(0);

   // int fd;
    //ssize_t n;
    //char buff[MAXLINE+1];

    //if((n=read(readfd,buff,MAXLINE))==0)
     //err_quit("read file error!");
   //while((n=readline(readfd,buff,MAXLINE))>0)
   //{
   // writefd = open(FIFO2,O_WRONLY,0);
    //if(buff[n-1]=='\n')
    //n--;
    //buff[n]='\0';

   // if((fd=open(buff,O_RDONLY))<0){
   // snprintf(buff+n,sizeof(buff)-n,":can't open,$s\n",strerror(errno));


    //n = strlen(buff);
    //close(fd);
    //unlink(readfd);
    //exit(0);
    //}
    //else
   // {
        //if((n=read(fd,buff,MAXLINE))>0)
       //{
            //write(writefd,buff,n);
        //}
        //close(fd);
        //close(writefd);

    //}


    //unlink(FIFO2);


//}

   //exit(0);

    
//}


    //close(readfd);
    //close(writefd);

   // unlink(FIFO1);

}
e/zaf/NetWork/muduo-master/muduo/base/cmake_install.cmake")
  include("/home/zaf/NetWork/muduo-master/muduo/net/cmake_install.cmake")
  include("/home/zaf/NetWork/muduo-master/contrib/cmake_install.cmake")
  include("/home/zaf/NetWork/muduo-master/examples/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/zaf/NetWork/muduo-master/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
shadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_base.dir/CurrentThread.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/CurrentThread.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/CurrentThread.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_base.dir/Date.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/Date.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/Date.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_base.dir/Exception.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/Exception.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/Exception.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_base.dir/FileUtil.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/FileUtil.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/FileUtil.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_base.dir/LogFile.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/LogFile.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/LogFile.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_base.dir/Logging.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/Logging.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/Logging.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_base.dir/LogStream.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/LogStream.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/LogStream.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_base.dir/ProcessInfo.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/ProcessInfo.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/ProcessInfo.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_base.dir/Timestamp.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/Timestamp.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/Timestamp.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_base.dir/Thread.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/Thread.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/Thread.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_base.dir/ThreadPool.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/ThreadPool.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/ThreadPool.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_base.dir/TimeZone.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/TimeZone.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/TimeZone.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/logging_test.dir/Logging_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/Logging_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/Logging_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/gzipfile_test.dir/GzipFile_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/GzipFile_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/GzipFile_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/fork_test.dir/Fork_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/Fork_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/Fork_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/logfile_test.dir/LogFile_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/LogFile_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/LogFile_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/boundedblockingqueue_test.dir/BoundedBlockingQueue_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/BoundedBlockingQueue_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/BoundedBlockingQueue_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/date_unittest.dir/Date_unittest.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/Date_unittest.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/Date_unittest.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/fileutil_test.dir/FileUtil_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/FileUtil_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/FileUtil_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/logstream_bench.dir/LogStream_bench.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/LogStream_bench.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/LogStream_bench.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/exception_test.dir/Exception_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/Exception_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/Exception_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/threadlocalsingleton_test.dir/ThreadLocalSingleton_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/ThreadLocalSingleton_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/ThreadLocalSingleton_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/timezone_unittest.dir/TimeZone_unittest.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/TimeZone_unittest.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/TimeZone_unittest.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/blockingqueue_bench.dir/BlockingQueue_bench.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/BlockingQueue_bench.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/BlockingQueue_bench.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/blockingqueue_test.dir/BlockingQueue_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/BlockingQueue_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/BlockingQueue_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/asynclogging_test.dir/AsyncLogging_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/AsyncLogging_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/AsyncLogging_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/blockingqueue_bench2.dir/BlockingQueue_bench2.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/BlockingQueue_bench2.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/BlockingQueue_bench2.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/logstream_test.dir/LogStream_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/LogStream_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/LogStream_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/mutex_test.dir/Mutex_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/Mutex_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/Mutex_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/atomic_unittest.dir/Atomic_unittest.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/Atomic_unittest.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/Atomic_unittest.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/processinfo_test.dir/ProcessInfo_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/ProcessInfo_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/ProcessInfo_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/singleton_threadlocal_test.dir/SingletonThreadLocal_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/SingletonThreadLocal_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/SingletonThreadLocal_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/timestamp_unittest.dir/Timestamp_unittest.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/Timestamp_unittest.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/Timestamp_unittest.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/singleton_test.dir/Singleton_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/Singleton_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/Singleton_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/thread_test.dir/Thread_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/Thread_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/Thread_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/threadlocal_test.dir/ThreadLocal_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/ThreadLocal_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/ThreadLocal_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/threadpool_test.dir/ThreadPool_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/ThreadPool_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/ThreadPool_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/base/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/thread_bench.dir/Thread_bench.cc.o -c /home/zaf/NetWork/muduo-master/muduo/base/tests/Thread_bench.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/base/tests/Thread_bench.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/Acceptor.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/Acceptor.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/Acceptor.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/Buffer.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/Buffer.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/Buffer.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/Channel.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/Channel.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/Channel.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/Connector.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/Connector.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/Connector.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/EventLoop.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/EventLoop.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/EventLoop.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/EventLoopThread.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/EventLoopThread.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/EventLoopThread.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/EventLoopThreadPool.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/EventLoopThreadPool.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/EventLoopThreadPool.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/InetAddress.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/InetAddress.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/InetAddress.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/Poller.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/Poller.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/Poller.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/poller/DefaultPoller.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/poller/DefaultPoller.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/poller/DefaultPoller.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/poller/EPollPoller.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/poller/EPollPoller.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/poller/EPollPoller.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/poller/PollPoller.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/poller/PollPoller.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/poller/PollPoller.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/Socket.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/Socket.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/Socket.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/SocketsOps.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/SocketsOps.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/SocketsOps.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/TcpClient.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/TcpClient.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/TcpClient.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/TcpConnection.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/TcpConnection.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/TcpConnection.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/TcpServer.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/TcpServer.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/TcpServer.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/Timer.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/Timer.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/Timer.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_net.dir/TimerQueue.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/TimerQueue.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/TimerQueue.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/http",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/httprequest_unittest.dir/tests/HttpRequest_unittest.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/http/tests/HttpRequest_unittest.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/http/tests/HttpRequest_unittest.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/http",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/httpserver_test.dir/tests/HttpServer_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/http/tests/HttpServer_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/http/tests/HttpServer_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/http",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_http.dir/HttpServer.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/http/HttpServer.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/http/HttpServer.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/http",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_http.dir/HttpResponse.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/http/HttpResponse.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/http/HttpResponse.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/http",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_http.dir/HttpContext.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/http/HttpContext.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/http/HttpContext.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/inspect",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/inspector_test.dir/tests/Inspector_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/inspect/tests/Inspector_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/inspect/tests/Inspector_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/inspect",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_inspect.dir/Inspector.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/inspect/Inspector.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/inspect/Inspector.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/inspect",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_inspect.dir/PerformanceInspector.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/inspect/PerformanceInspector.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/inspect/PerformanceInspector.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/inspect",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_inspect.dir/ProcessInspector.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/inspect/ProcessInspector.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/inspect/ProcessInspector.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/inspect",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_inspect.dir/SystemInspector.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/inspect/SystemInspector.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/inspect/SystemInspector.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/channel_test.dir/Channel_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/tests/Channel_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/tests/Channel_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/eventloopthreadpool_unittest.dir/EventLoopThreadPool_unittest.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/tests/EventLoopThreadPool_unittest.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/tests/EventLoopThreadPool_unittest.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/echoserver_unittest.dir/EchoServer_unittest.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/tests/EchoServer_unittest.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/tests/EchoServer_unittest.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/echoclient_unittest.dir/EchoClient_unittest.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/tests/EchoClient_unittest.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/tests/EchoClient_unittest.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/buffer_unittest.dir/Buffer_unittest.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/tests/Buffer_unittest.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/tests/Buffer_unittest.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/inetaddress_unittest.dir/InetAddress_unittest.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/tests/InetAddress_unittest.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/tests/InetAddress_unittest.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/eventloopthread_unittest.dir/EventLoopThread_unittest.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/tests/EventLoopThread_unittest.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/tests/EventLoopThread_unittest.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/zlibstream_unittest.dir/ZlibStream_unittest.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/tests/ZlibStream_unittest.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/tests/ZlibStream_unittest.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/tcpclient_reg2.dir/TcpClient_reg2.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/tests/TcpClient_reg2.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/tests/TcpClient_reg2.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/eventloop_unittest.dir/EventLoop_unittest.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/tests/EventLoop_unittest.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/tests/EventLoop_unittest.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/tcpclient_reg3.dir/TcpClient_reg3.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/tests/TcpClient_reg3.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/tests/TcpClient_reg3.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/tcpclient_reg1.dir/TcpClient_reg1.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/tests/TcpClient_reg1.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/tests/TcpClient_reg1.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/tests",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/timerqueue_unittest.dir/TimerQueue_unittest.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/tests/TimerQueue_unittest.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/tests/TimerQueue_unittest.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/protobuf",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -Wno-error=shadow -o CMakeFiles/muduo_protobuf_codec.dir/ProtobufCodecLite.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/protobuf/ProtobufCodecLite.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/protobuf/ProtobufCodecLite.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/protorpc",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -Wno-error=shadow -o CMakeFiles/muduo_protorpc.dir/RpcChannel.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/protorpc/RpcChannel.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/protorpc/RpcChannel.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/protorpc",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -Wno-error=shadow -o CMakeFiles/muduo_protorpc.dir/RpcServer.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/protorpc/RpcServer.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/protorpc/RpcServer.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/protorpc",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -Wno-error=shadow -o CMakeFiles/protobuf_rpc_wire_test.dir/RpcCodec_test.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/protorpc/RpcCodec_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/protorpc/RpcCodec_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/protorpc",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -Wno-error=shadow -Wno-conversion -o CMakeFiles/muduo_protorpc_wire.dir/rpc.pb.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/protorpc/rpc.pb.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/protorpc/rpc.pb.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/muduo/net/protorpc",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -Wno-error=shadow -o CMakeFiles/muduo_protorpc_wire.dir/RpcCodec.cc.o -c /home/zaf/NetWork/muduo-master/muduo/net/protorpc/RpcCodec.cc",
  "file": "/home/zaf/NetWork/muduo-master/muduo/net/protorpc/RpcCodec.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/contrib/hiredis",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/mrediscli.dir/Hiredis.cc.o -c /home/zaf/NetWork/muduo-master/contrib/hiredis/Hiredis.cc",
  "file": "/home/zaf/NetWork/muduo-master/contrib/hiredis/Hiredis.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/contrib/hiredis",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/mrediscli.dir/mrediscli.cc.o -c /home/zaf/NetWork/muduo-master/contrib/hiredis/mrediscli.cc",
  "file": "/home/zaf/NetWork/muduo-master/contrib/hiredis/mrediscli.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/contrib/thrift",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_thrift.dir/ThriftConnection.cc.o -c /home/zaf/NetWork/muduo-master/contrib/thrift/ThriftConnection.cc",
  "file": "/home/zaf/NetWork/muduo-master/contrib/thrift/ThriftConnection.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/contrib/thrift",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_thrift.dir/ThriftServer.cc.o -c /home/zaf/NetWork/muduo-master/contrib/thrift/ThriftServer.cc",
  "file": "/home/zaf/NetWork/muduo-master/contrib/thrift/ThriftServer.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/asio/chat",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/asio_chat_server_threaded_efficient.dir/server_threaded_efficient.cc.o -c /home/zaf/NetWork/muduo-master/examples/asio/chat/server_threaded_efficient.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/asio/chat/server_threaded_efficient.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/asio/chat",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/asio_chat_server_threaded.dir/server_threaded.cc.o -c /home/zaf/NetWork/muduo-master/examples/asio/chat/server_threaded.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/asio/chat/server_threaded.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/asio/chat",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/asio_chat_server_threaded_highperformance.dir/server_threaded_highperformance.cc.o -c /home/zaf/NetWork/muduo-master/examples/asio/chat/server_threaded_highperformance.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/asio/chat/server_threaded_highperformance.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/asio/chat",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/asio_chat_server.dir/server.cc.o -c /home/zaf/NetWork/muduo-master/examples/asio/chat/server.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/asio/chat/server.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/asio/chat",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/asio_chat_loadtest.dir/loadtest.cc.o -c /home/zaf/NetWork/muduo-master/examples/asio/chat/loadtest.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/asio/chat/loadtest.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/asio/chat",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/asio_chat_client.dir/client.cc.o -c /home/zaf/NetWork/muduo-master/examples/asio/chat/client.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/asio/chat/client.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/asio/tutorial",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/asio_tutorial_timer6.dir/timer6/timer.cc.o -c /home/zaf/NetWork/muduo-master/examples/asio/tutorial/timer6/timer.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/asio/tutorial/timer6/timer.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/asio/tutorial",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/asio_tutorial_timer4.dir/timer4/timer.cc.o -c /home/zaf/NetWork/muduo-master/examples/asio/tutorial/timer4/timer.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/asio/tutorial/timer4/timer.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/asio/tutorial",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/asio_tutorial_timer3.dir/timer3/timer.cc.o -c /home/zaf/NetWork/muduo-master/examples/asio/tutorial/timer3/timer.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/asio/tutorial/timer3/timer.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/asio/tutorial",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/asio_tutorial_timer5.dir/timer5/timer.cc.o -c /home/zaf/NetWork/muduo-master/examples/asio/tutorial/timer5/timer.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/asio/tutorial/timer5/timer.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/asio/tutorial",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/asio_tutorial_timer2.dir/timer2/timer.cc.o -c /home/zaf/NetWork/muduo-master/examples/asio/tutorial/timer2/timer.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/asio/tutorial/timer2/timer.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/fastcgi",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/fastcgi_test.dir/fastcgi.cc.o -c /home/zaf/NetWork/muduo-master/examples/fastcgi/fastcgi.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/fastcgi/fastcgi.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/fastcgi",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/fastcgi_test.dir/fastcgi_test.cc.o -c /home/zaf/NetWork/muduo-master/examples/fastcgi/fastcgi_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/fastcgi/fastcgi_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/fastcgi",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/fastcgi_test.dir/__/sudoku/sudoku.cc.o -c /home/zaf/NetWork/muduo-master/examples/sudoku/sudoku.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/sudoku/sudoku.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/filetransfer",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/filetransfer_download3.dir/download3.cc.o -c /home/zaf/NetWork/muduo-master/examples/filetransfer/download3.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/filetransfer/download3.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/filetransfer",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/filetransfer_download2.dir/download2.cc.o -c /home/zaf/NetWork/muduo-master/examples/filetransfer/download2.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/filetransfer/download2.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/filetransfer",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/filetransfer_download.dir/download.cc.o -c /home/zaf/NetWork/muduo-master/examples/filetransfer/download.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/filetransfer/download.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/hub",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/sub.dir/sub.cc.o -c /home/zaf/NetWork/muduo-master/examples/hub/sub.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/hub/sub.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/hub",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/pub.dir/pub.cc.o -c /home/zaf/NetWork/muduo-master/examples/hub/pub.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/hub/pub.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/hub",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_pubsub.dir/pubsub.cc.o -c /home/zaf/NetWork/muduo-master/examples/hub/pubsub.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/hub/pubsub.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/hub",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/muduo_pubsub.dir/codec.cc.o -c /home/zaf/NetWork/muduo-master/examples/hub/codec.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/hub/codec.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/hub",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/hub.dir/hub.cc.o -c /home/zaf/NetWork/muduo-master/examples/hub/hub.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/hub/hub.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/hub",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/hub.dir/codec.cc.o -c /home/zaf/NetWork/muduo-master/examples/hub/codec.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/hub/codec.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/idleconnection",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/idleconnection_echo2.dir/sortedlist.cc.o -c /home/zaf/NetWork/muduo-master/examples/idleconnection/sortedlist.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/idleconnection/sortedlist.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/idleconnection",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/idleconnection_echo.dir/echo.cc.o -c /home/zaf/NetWork/muduo-master/examples/idleconnection/echo.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/idleconnection/echo.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/idleconnection",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/idleconnection_echo.dir/main.cc.o -c /home/zaf/NetWork/muduo-master/examples/idleconnection/main.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/idleconnection/main.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/maxconnection",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/maxconnection_echo.dir/echo.cc.o -c /home/zaf/NetWork/muduo-master/examples/maxconnection/echo.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/maxconnection/echo.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/maxconnection",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/maxconnection_echo.dir/main.cc.o -c /home/zaf/NetWork/muduo-master/examples/maxconnection/main.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/maxconnection/main.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/memcached/server",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/memcached_footprint.dir/Item.cc.o -c /home/zaf/NetWork/muduo-master/examples/memcached/server/Item.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/memcached/server/Item.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/memcached/server",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/memcached_footprint.dir/MemcacheServer.cc.o -c /home/zaf/NetWork/muduo-master/examples/memcached/server/MemcacheServer.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/memcached/server/MemcacheServer.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/memcached/server",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/memcached_footprint.dir/Session.cc.o -c /home/zaf/NetWork/muduo-master/examples/memcached/server/Session.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/memcached/server/Session.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/memcached/server",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/memcached_footprint.dir/footprint_test.cc.o -c /home/zaf/NetWork/muduo-master/examples/memcached/server/footprint_test.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/memcached/server/footprint_test.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/multiplexer",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/multiplex_demux.dir/demux.cc.o -c /home/zaf/NetWork/muduo-master/examples/multiplexer/demux.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/multiplexer/demux.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/multiplexer",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/multiplex_server_simple.dir/multiplexer_simple.cc.o -c /home/zaf/NetWork/muduo-master/examples/multiplexer/multiplexer_simple.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/multiplexer/multiplexer_simple.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/multiplexer",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/multiplex_server.dir/multiplexer.cc.o -c /home/zaf/NetWork/muduo-master/examples/multiplexer/multiplexer.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/multiplexer/multiplexer.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/netty/discard",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/netty_discard_server.dir/server.cc.o -c /home/zaf/NetWork/muduo-master/examples/netty/discard/server.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/netty/discard/server.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/netty/discard",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/netty_discard_client.dir/client.cc.o -c /home/zaf/NetWork/muduo-master/examples/netty/discard/client.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/netty/discard/client.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/netty/echo",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/netty_echo_server2.dir/server2.cc.o -c /home/zaf/NetWork/muduo-master/examples/netty/echo/server2.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/netty/echo/server2.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/netty/echo",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/netty_echo_server.dir/server.cc.o -c /home/zaf/NetWork/muduo-master/examples/netty/echo/server.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/netty/echo/server.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/netty/echo",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/netty_echo_client.dir/client.cc.o -c /home/zaf/NetWork/muduo-master/examples/netty/echo/client.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/netty/echo/client.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/netty/uptime",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/netty_uptime.dir/uptime.cc.o -c /home/zaf/NetWork/muduo-master/examples/netty/uptime/uptime.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/netty/uptime/uptime.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/pingpong",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/pingpong_bench.dir/bench.cc.o -c /home/zaf/NetWork/muduo-master/examples/pingpong/bench.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/pingpong/bench.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/pingpong",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/pingpong_server.dir/server.cc.o -c /home/zaf/NetWork/muduo-master/examples/pingpong/server.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/pingpong/server.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/pingpong",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/pingpong_client.dir/client.cc.o -c /home/zaf/NetWork/muduo-master/examples/pingpong/client.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/pingpong/client.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/roundtrip",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/roundtrip_udp.dir/roundtrip_udp.cc.o -c /home/zaf/NetWork/muduo-master/examples/roundtrip/roundtrip_udp.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/roundtrip/roundtrip_udp.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/roundtrip",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/roundtrip.dir/roundtrip.cc.o -c /home/zaf/NetWork/muduo-master/examples/roundtrip/roundtrip.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/roundtrip/roundtrip.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/shorturl",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/shorturl.dir/shorturl.cc.o -c /home/zaf/NetWork/muduo-master/examples/shorturl/shorturl.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/shorturl/shorturl.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/simple",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/simple_chargen.dir/chargen/chargen.cc.o -c /home/zaf/NetWork/muduo-master/examples/simple/chargen/chargen.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/simple/chargen/chargen.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/simple",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/simple_chargen.dir/chargen/main.cc.o -c /home/zaf/NetWork/muduo-master/examples/simple/chargen/main.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/simple/chargen/main.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/simple",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/simple_daytime.dir/daytime/daytime.cc.o -c /home/zaf/NetWork/muduo-master/examples/simple/daytime/daytime.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/simple/daytime/daytime.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/simple",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/simple_daytime.dir/daytime/main.cc.o -c /home/zaf/NetWork/muduo-master/examples/simple/daytime/main.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/simple/daytime/main.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/simple",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/simple_echo.dir/echo/echo.cc.o -c /home/zaf/NetWork/muduo-master/examples/simple/echo/echo.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/simple/echo/echo.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/simple",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/simple_echo.dir/echo/main.cc.o -c /home/zaf/NetWork/muduo-master/examples/simple/echo/main.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/simple/echo/main.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/simple",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/simple_time.dir/time/time.cc.o -c /home/zaf/NetWork/muduo-master/examples/simple/time/time.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/simple/time/time.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/simple",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/simple_time.dir/time/main.cc.o -c /home/zaf/NetWork/muduo-master/examples/simple/time/main.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/simple/time/main.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/simple",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/simple_allinone.dir/allinone/allinone.cc.o -c /home/zaf/NetWork/muduo-master/examples/simple/allinone/allinone.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/simple/allinone/allinone.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/simple",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/simple_allinone.dir/chargen/chargen.cc.o -c /home/zaf/NetWork/muduo-master/examples/simple/chargen/chargen.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/simple/chargen/chargen.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/simple",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/simple_allinone.dir/daytime/daytime.cc.o -c /home/zaf/NetWork/muduo-master/examples/simple/daytime/daytime.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/simple/daytime/daytime.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/simple",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/simple_allinone.dir/discard/discard.cc.o -c /home/zaf/NetWork/muduo-master/examples/simple/discard/discard.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/simple/discard/discard.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/simple",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -DNDEBUG   -o CMakeFiles/simple_allinone.dir/echo/echo.cc.o -c /home/zaf/NetWork/muduo-master/examples/simple/echo/echo.cc",
  "file": "/home/zaf/NetWork/muduo-master/examples/simple/echo/echo.cc"
},
{
  "directory": "/home/zaf/NetWork/muduo-master/examples/simple",
  "command": "/usr/bin/c++   -I/home/zaf/NetWork/muduo-master  -g -DCHECK_PTHREAD_RETURN_VALUE -D_FILE_OFFSET_BITS=64 -Wall -Wextra -Werror -Wconversion -Wno-unused-parameter -Wold-style-cast -Woverloaded-virtual -Wpointer-arith -Wshadow -Wwrite-strings -march=native -std=c++11 -rdynamic -O2 -D