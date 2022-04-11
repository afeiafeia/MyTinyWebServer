cmake_minimum_required(VERSION 3.10)
#SET(CMAKE_BUILD_TYPE "Debug")
#SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

add_executable(EventLoop_Test EventLoop_Test.cpp)
target_link_libraries(EventLoop_Test libnet)