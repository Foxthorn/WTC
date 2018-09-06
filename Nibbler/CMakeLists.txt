cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(nibbler)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -stdlib=libc++")

add_executable(
    nibbler
    main.cpp
    Game.cpp
    Factory.cpp
    Snake.cpp
    ScreenObject.cpp   
)
    
add_subdirectory(SDL)