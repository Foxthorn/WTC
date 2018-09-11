cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(nibbler)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -stdlib=libc++")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

add_executable(
    nibbler
    src/main.cpp
    src/Game.cpp
    src/Factory.cpp
    src/Snake.cpp
    src/ScreenObject.cpp   
)
    
add_subdirectory(SDL)

add_subdirectory(SFML)

add_subdirectory(OPENGL)