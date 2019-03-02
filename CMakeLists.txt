cmake_minimum_required(VERSION 3.9)

# project settings

project(plugin_test CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# sources

add_subdirectory(core)
add_subdirectory(plugin)
