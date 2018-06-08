cmake_minimum_required(VERSION 3.10)
project(dev-library-cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(dev-library-cpp main.cpp)
add_executable(strategy design-patterns/fundamental-patterns/behavioral/strategy/main.cpp)

add_subdirectory(architecture)
add_subdirectory(cpp-core/WinAPI/01)
add_subdirectory(cpp-core/WinAPI/02)