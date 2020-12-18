cmake_minimum_required(VERSION 3.5)
project(hello_shared)

add_library(libshared #生成一个target library为单数
	SHARED
	src/Hello.cpp)
add_library(otherlibrary ALIAS libshared)
target_include_directories(libshared #可能使用多个include,为复数
	PUBLIC
	${CMAKE_SOURCE_DIR}/include
)
add_executable(${PROJECT_NAME}
	src/main.cpp
)
target_link_libraries(hello_shared
	PRIVATE
	otherlibrary
)
