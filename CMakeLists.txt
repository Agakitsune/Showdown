cmake_minimum_required(VERSION 3.22)
project(showdown)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCE
    $(PROJECT_SOURCE_DIR)/src/*.cpp
)

add_executable(showdown
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${SOURCE}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
