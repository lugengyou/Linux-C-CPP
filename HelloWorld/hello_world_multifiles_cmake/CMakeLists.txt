
cmake_minimum_required(VERSION 3.1)

project(HelloWorld VERSION 0.1)

# 生成库文件目标
add_library(MyLib MyLib.cpp MyLib.h)

# 生成可执行文件目标
add_executable(HelloWorld hello_world.cpp)

# 将可执行文件目标 链接到 生成库文件目标
target_link_libraries(HelloWorld PRIVATE MyLib)
