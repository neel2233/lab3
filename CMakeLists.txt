cmake_minimum_required(VERSION 3.25)
									
set(PROJECT_NAME project)				 		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_definitions(-DSFML_STATIC)		 
	
include_directories("files/")

add_executable("${PROJECT_NAME}" main.cpp
				files/Matrix.hpp
			
)
											
