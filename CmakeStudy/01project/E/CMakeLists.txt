cmake_minimum_required(VERSION 3.5)
project(Hello_install)
add_library(libhello
	SHARED src/Hello.cpp)
target_include_directories(libhello
	PUBLIC 
	${PROJECT_SOURCE_DIR}/include)
add_executable(${PROJECT_NAME}
	src/main.cpp)
target_link_libraries(Hello_install
	PRIVATE
	libhello)
#library:
install (TARGETS libhello 
	LIBRARY
	DESTINATION lib)
#Binaries
install (TARGETS Hello_install
	DESTINATION bin)
#Header files
install (DIRECTORY ${PROJECT_SOURCE_DIR}/include
	DESTINATION )
#Config
#install (FILES cmake-examples.conf DESTINATION etc)

