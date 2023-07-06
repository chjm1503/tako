cmake_minimum_required(VERSION 3.0)
project(Tako LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

option(TAKO_BUILD_WORLD  "Build one dll"        OFF)
option(TAKO_BUILD_SHARED "Build shared library" ON)

add_subdirectory(${CMAKE_SOURCE_DIR}/TakoLibrary/LibTako)