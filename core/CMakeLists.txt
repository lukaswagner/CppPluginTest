cmake_minimum_required(VERSION 3.9)

# sources

set(source_dir src)
set(include_dir include)
set(interface_dir interface)

set(headers
    ${interface_dir}/plugin.hpp
    ${include_dir}/pluginLoader.hpp)

set(sources
    ${source_dir}/main.cpp
    ${source_dir}/pluginLoader.cpp)

# executable

include_directories(${include_dir})
include_directories(${interface_dir})
add_executable(core ${headers} ${sources})
set(VS_STARTUP_PROJECT core)
