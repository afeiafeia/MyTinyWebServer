cmake_minimum_required(VERSION 3.10)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(LIB_SRC
    MutexLock.cpp
    FileUtil.cpp
    LogFile.cpp
    Logger.cpp
    Thread.cpp
    AsyncLogger.cpp
    Semaphore.cpp
    LogLevel.cpp
    LogEvent.cpp
    LogFormatter.cpp
    FileLogAppender.cpp
    LogEventWarp.cpp
    Logger.cpp
    ./net/EventLoop.cpp
    ./net/EventLoopThread.cpp
    ./net/EventLoopThreadPool.cpp
    ./net/Channel.cpp
    ./net/EpollPoller.cpp

)
add_library(base ${LIB_SRC})
target_link_libraries(base pthread rt)

set_target_properties(base PROPERTIES OUTPUT_NAME "base")

add_executable(LogTest LogTest.cpp)
target_link_libraries(LogTest base)

add_executable(EventLoop_Test EventLoop_Test.cpp)
target_link_libraries(EventLoop_Test base)