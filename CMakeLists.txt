cmake_minimum_required(VERSION 3.10.0)
project(VSTest VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC_FILES "./src/*.cpp")

include_directories(${PROJECT_SOURCE_DIR}/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(VSTest main.cpp ${SRC_FILES})

# 필요한 라이브러리 경로 정의
if(UNIX)
 if(CMAKE_C_COMPILER MATCHES "/usr/bin/x86_64-w64-mingw32-gcc" AND CMAKE_CXX_COMPILER MATCHES "/usr/bin/x86_64-w64-mingw32-g++")
  set(REQUIRED_LIBS
  "/usr/lib/gcc/x86_64-w64-mingw32/13-win32/libstdc++-6.dll"
  "/usr/lib/gcc/x86_64-w64-mingw32/13-win32/libgcc_s_seh-1.dll"
  )
  endif()
endif()

foreach(lib ${REQUIRED_LIBS})
    add_custom_command(TARGET VSTest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${lib} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    )
endforeach()