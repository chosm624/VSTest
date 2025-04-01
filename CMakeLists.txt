cmake_minimum_required(VERSION 3.10.0)
project(VSTest VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC_FILES "./src/*.cpp")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(VSTest main.cpp ${SRC_FILES})

