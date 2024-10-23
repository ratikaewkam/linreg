cmake_minimum_required(VERSION 3.25)

project(linreg)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(linreg STATIC lib/linreg/src/linreg.cpp)

target_include_directories(linreg PUBLIC lib/linreg/include)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE linreg)