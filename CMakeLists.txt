cmake_minimum_required(VERSION 3.10)
project(dev-library-cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(dev-library-cpp main.cpp)
add_executable(
        architecture architecture/main.cpp
        architecture/Entity.cpp
        architecture/Entity.h
)
add_executable(strategy design-patterns/fundamental-patterns/behavioral/strategy/main.cpp)
add_executable(WinApi_01 cpp-core/WinAPI/01/main.cpp)
#add_executable(WinApi_02 cpp-core/WinAPI/02/main.cpp)
add_executable(WinApi_03 cpp-core/WinAPI/03/main.cpp)