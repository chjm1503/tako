set(MODULE_NAME TakoLog)

file(GLOB Source *.c *.cpp *.cxx *.cc)
file(GLOB Header *.h *.hpp)
add_library(lib${MODULE_NAME} ${Source} ${Header})
target_include_directories(lib${MODULE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (TAKO_BUILD_SHARED STREQUAL "ON")
    add_library(${MODULE_NAME} SHARED ${Source} ${Header})
endif ()