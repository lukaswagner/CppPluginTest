cmake_minimum_required(VERSION 3.9)

# sources

set(source_dir src)
set(include_dir include)
set(interface_dir interface)

set(headers
    ${include_dir}/pluginLoader.hpp)

set(sources
    ${source_dir}/main.cpp
    ${source_dir}/pluginLoader.cpp)

# public vars for building plugins

set (plugin_interface_header_dir
    ${CMAKE_CURRENT_SOURCE_DIR}/${interface_dir}
    PARENT_SCOPE)

set (plugin_export_header
    ${CMAKE_CURRENT_SOURCE_DIR}/${interface_dir}/pluginExports.hpp
    PARENT_SCOPE)

# include dirs

include_directories(${include_dir})
include_directories(${interface_dir})

# executable

add_executable(core ${headers} ${sources})
set(VS_STARTUP_PROJECT core)
