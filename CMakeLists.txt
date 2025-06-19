cmake_minimum_required(VERSION 3.10)
project(MyProjectName VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MyExecutableName
        main25b2.cpp
        dspotify25b2.cpp
        dspotify25b2.h
        wet2util.h
        Nodes/Node.h
        Nodes/Node.cpp
)

target_include_directories(MyExecutableName PRIVATE include)