cmake_minimum_required (VERSION 3.4)
project (MultiThreading)

# Add iclude directories
include_directories ("${PROJECT_SOURCE_DIR}")

# Use c++14
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Source files
set (MULTITHREAD_SOURCE_FILES main.cpp
                              threadfunctions.cpp)

# Add the executable
add_executable (MultiThreading ${MULTITHREAD_SOURCE_FILES})

# Find and add required multithreading library
find_package(Threads REQUIRED)
target_link_libraries(MultiThreading ${CMAKE_THREAD_LIBS_INIT})
