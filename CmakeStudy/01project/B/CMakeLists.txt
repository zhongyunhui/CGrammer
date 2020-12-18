cmake_minimum_required(VERSION 3.5)
project (hello_headers)
set (SOURCES
	src/Hello.cpp
	src/main.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME}
	PRIVATE 
	${CMAKE_SOURCE_DIR}/include
)

