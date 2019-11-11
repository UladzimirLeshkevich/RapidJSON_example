cmake_minimum_required(VERSION 3.5)

project(example_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(example_1 main.cpp
                         parser.cpp
                         parser.h)
#add_subdirectory (include/rapidjson)

file(GLOB json test.json)
file(COPY ${json} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
