cmake_minimum_required(VERSION 3.10)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set (
    LIB_SRC
    ../base/MutexLock.cpp
    ../base/Logger.cpp
    ../base/Thread.cpp
    ../base/Semaphore.cpp
    ../base/LogLevel.cpp
    ../base/LogEvent.cpp
    ../base/LogFormatter.cpp
    ../base/LogFileAppender.cpp
    ../base/LogEventWarp.cpp
    ../base/Logger.cpp
)
set(LIB_NET
    EventLoop.cpp
    EventLoopThread.cpp
    EventLoopThreadPool.cpp
    Channel.cpp
    EpollPoller.cpp
    Acceptor.cpp
    TcpServer.cpp
    TcpConnection.cpp
    EchoServer.cpp
    Buffer.cpp
    ./protobuf/CodeC.cpp
    ${LIB_SRC}
)
add_library(my_tiny_muduo_net ${LIB_NET})
target_link_libraries(my_tiny_muduo_net pthread rt)
#set_target_properties((my_tiny_muduo_net PROPERTIES OUTPUT_NAME "net")

add_subdirectory(test)
#add_executable(Test_EventLoop Test_EventLoop.cpp)
#target_link_libraries(Test_EventLoop my_tiny_muduo_net)


