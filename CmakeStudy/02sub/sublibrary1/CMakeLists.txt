project(SubLibrary1)

add_library(${PROJECT_NAME} SHARED src/sublib1.cpp)
add_library(sub::lib1 ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}
	PUBLIC ${PROJECT_SOURCE_DIR}/include)
