cmake_minimum_required(VERSION 3.5)
project(CXX_standard)
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)


#if(COMPILER_SUPPORTS_CXX14) set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
#elseif(COMPILER_SUPPORTS_CXX11) set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#else()	message(STATUS "THE compiler ${CMAKE_CXX_COMPILER} has no mordern support")
#endif()
add_executable(CXX_standard_example main.cpp)

