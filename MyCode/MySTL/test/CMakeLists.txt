include_directories(${PROJECT_SOURCE_DIR}/src)
set(APP_SRC test_main.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(stltest ${APP_SRC})