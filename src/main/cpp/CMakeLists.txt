cmake_minimum_required(VERSION 3.0)

project(tako4cc LANGUAGES C CXX)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # Force MSVC to use UTF-8 because that's what we use. Otherwise it uses
    # the default of whatever Windows sets and causes encoding issues.
    message(STATUS "You are using MSVC. Forceing to use UTF-8")
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif ()

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

add_executable(tako4cc main.cc)