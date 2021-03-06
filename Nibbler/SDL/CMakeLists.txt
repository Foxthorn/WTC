cmake_minimum_required (VERSION 3.11 FATAL_ERROR)

project(SDL)

include(FetchContent)

FetchContent_Declare(
    sdl_download
    URL https://www.libsdl.org/release/SDL2-2.0.8.zip
)

FetchContent_GetProperties(sfml_download)

if(NOT sdl_download_POPULATED)
    FetchContent_Populate(sdl_download)
    add_subdirectory(${sdl_download_SOURCE_DIR} ${sdl_download_BINARY_DIR})
endif()

include_directories(
    ${sdl_download_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR})

# sdl lib
add_library(sdl SHARED
        Functions.cpp
)

target_link_libraries(sdl SDL2main SDL2)