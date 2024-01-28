# 指定使用的 cmake 的最低版本
cmake_minimum_required(VERSION 3.0)

# 定义工程名称，并可指定工程的版本、工程描述、web主页地址、支持的语言（默认情况支持所有语言）
# 如果不需要这些都是可以忽略的，只需要指定出工程名字即可。
project(speechSystem)

# 定义工程会生成一个可执行程序
add_executable(app speaker.cpp speechManager.cpp main.cpp)


