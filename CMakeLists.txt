cmake_minimum_required(VERSION 3.10)
project(dev-library-cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(dev-library-cpp main.cpp)

add_subdirectory(architecture)
add_subdirectory(design-patterns)
add_subdirectory(frameworks)
add_subdirectory(cpp-core)