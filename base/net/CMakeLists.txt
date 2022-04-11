cmake_minimum_required(VERSION 3.10)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(LIB_NET
    EventLoop.cpp
    EventLoopThread.cpp
    EventLoopThreadPool.cpp
    Channel.cpp
    EpollPoller.cpp

)
add_library(net ${LIB_NET})
target_link_libraries(net base)

set_target_properties(net PROPERTIES OUTPUT_NAME "net")

add_executable(EventLoop_Test EventLoop_Test.cpp)
target_link_libraries(EventLoop_Test net)
