cmake_minimum_required(VERSION 3.10)

project(StackSmashing)

add_executable(vulnerable vulnerable.cpp)
set_property(TARGET vulnerable PROPERTY CXX_STANDARD 23)
target_compile_options(vulnerable PRIVATE -fno-stack-protector)

add_executable(safe vulnerable.cpp)
set_property(TARGET safe PROPERTY CXX_STANDARD 23)
target_compile_options(safe PRIVATE -fstack-protector)

enable_testing()

add_test(NAME VulnerableTest COMMAND "${CMAKE_SOURCE_DIR}\\run.sh" $<TARGET_FILE:vulnerable>)
add_test(NAME SafeTest COMMAND "${CMAKE_SOURCE_DIR}\\run.sh" $<TARGET_FILE:safe>)
set_tests_properties(SafeTest PROPERTIES WILL_FAIL True)