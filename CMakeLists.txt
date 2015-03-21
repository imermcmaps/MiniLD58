cmake_minimum_required(VERSION 2.8.4)
project(MiniLD58)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(Engine ${CMAKE_CURRENT_BINARY_DIR}/engine)
include("Engine/includes.cmake")
include_directories(.)

set(SOURCE_FILES 
				main.cpp
)
add_executable(MiniLD58 ${SOURCE_FILES})

target_link_libraries(MiniLD58 Engine)
