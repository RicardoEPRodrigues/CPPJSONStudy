cmake_minimum_required(VERSION 3.7)
project(JSONStudy)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic -g3 -Og -Wuninitialized")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ofast")

set(SOURCE_FILES main.cpp
        json.hpp
        Looper.cpp Looper.h)
add_executable(JSONStudy ${SOURCE_FILES})