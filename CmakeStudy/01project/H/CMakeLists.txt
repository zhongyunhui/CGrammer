cmake_minimum_required(VERSION 3.5)
project(third_library)
#使用文件系统和系统查找boost install
find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)
if(Boost_FOUND)
	message("boost found")
else()
	message(FATAL_ERROR "Cannot find boost")
endif()
add_executable(third_library_example main.cpp)
target_link_libraries(third_library_example
	PRIVATE ${Boost_LIBRARIES})
