cmake_minimum_required(VERSION 3.10)

project(StackSmashing)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-stack-protector")

add_executable(vulnerable vulnerable.cpp)
set_property(TARGET vulnerable PROPERTY CXX_STANDARD 23)

enable_testing()
add_test(NAME MainTest COMMAND run.sh $<TARGET_FILE:vulnerable>)