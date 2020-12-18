cmake_minimum_required(VERSION 3.5)
project(hello_three)
set(SOURCES 
	src/main.cpp
	src/Hello.cpp
)
add_executable(${PROJECT_NAME} 
	src/main.cpp)
#将hello_library链接到可执行文件，为hello_three添加链接库
#被链接的库如果有INTERFACE或者PUBLIC属性的包含目录，该包含目录会被传递给可执行文件
target_link_libraries(${PROJECT_NAME}
	PRIVATE#因为生成的可执行文件不会被链接，所以定义为PRIVATE
	hello_library
)
#创建一个静态库libhello_library.a
add_library(hello_library STATIC
	src/Hello.cpp
)
#该目录两种情况被调用：1.编译库时会使用,2.编译链接到这个hello_library时
#PRIVATE:目录放入target的包含路径，
#INTERFACE:目录没有被添加，而是链接了这个库的其他目标包含路径
#PUBLIC:目录既被添加到包含路径，或者添加到了链接了这个库的其他目标的包含路径

target_include_directories(hello_library
	PUBLIC
	${PROJECT_SOURCE_DIR}/include
)	



