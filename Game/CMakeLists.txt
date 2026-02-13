cmake_minimum_required(VERSION 3.10)
project(UNO)

set(CMAKE_CXX_STANDARD 17)

# Compilar todos los .cpp de src y sus subcarpetas
file(GLOB_RECURSE Sources "src/*.cpp")

# Incluir los directorios header
include_directories(src/)

add_executable(UNO ${Sources})