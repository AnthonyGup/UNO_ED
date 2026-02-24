cmake_minimum_required(VERSION 3.10)
project(UNO LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compilar todos los .cpp de src y sus subcarpetas
# CONFIGURE_DEPENDS permite que CMake reconfigure al agregar nuevos .cpp
file(GLOB_RECURSE Sources CONFIGURE_DEPENDS "src/*.cpp")

add_executable(UNO ${Sources})
target_include_directories(UNO PRIVATE src)

if(MSVC)
	target_compile_options(UNO PRIVATE /W4)
else()
	target_compile_options(UNO PRIVATE -Wall -Wextra -Wpedantic)
endif()