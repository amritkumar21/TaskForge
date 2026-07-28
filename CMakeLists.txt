cmake_minimum_required(VERSION 3.20)

project(TaskForge VERSION 1.0 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



add_executable(TaskForge
    src/main.cpp
    src/Task.cpp
    src/TaskQueue.cpp
    src/Worker.cpp
    src/Scheduler.cpp
    src/TaskComparator.cpp
)

target_include_directories(TaskForge PRIVATE include)