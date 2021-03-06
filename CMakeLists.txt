
cmake_minimum_required(VERSION 3.19)
project(lib_crc)

add_library( lib_crc STATIC
crc16.cpp
crc16.h
)

#USE interface to unclude lib path at project target
target_include_directories(lib_crc
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
          
install(TARGETS lib_crc DESTINATION .)

option(TEST_ALL "make google test bin" OFF)
option(TEST_CRCLIB "make google test bin" OFF)

option(DEBUG "debug configuration" OFF)

if(DEBUG)
       set(CMAKE_BUILD_TYPE Debug)
endif()


if(TEST_ALL OR TEST_CRCLIB)

 # googletest
add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest" 
    "googletest"
)

add_executable(
    test_crclib
    test/test.cpp
)

# Add src to the include directories for the test target
target_include_directories(
     test_crclib PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

# Link test target against gtest libraries
target_link_libraries(
    test_crclib PRIVATE
    gtest gtest_main
        lib_crc
)

target_compile_options(
        test_crclib PRIVATE
        -Wall 
        -Wextra 
        -pedantic 
        -std=c++17
        -lserialport
        #-Werror
)

endif()	