cmake_minimum_required(VERSION 3.9)

# sources

set(source_dir src)
set(include_dir include)
set(interface_dir ../interface)

set(headers
    ${include_dir}/pluginLoader.hpp)

set(sources
    ${source_dir}/main.cpp
    ${source_dir}/pluginLoader.cpp)

# include dirs

include_directories(${include_dir})
include_directories(${interface_dir})

# executable

add_executable(core ${headers} ${sources})
set(VS_STARTUP_PROJECT core)

# for unix: link dl

if(CMAKE_DL_LIBS)
    target_link_libraries(core ${CMAKE_DL_LIBS})
endif()

# check for filesystem

include(CheckIncludeFileCXX)
check_include_file_cxx("filesystem" filesystem_exists)
check_include_file_cxx("experimental/filesystem" experimental_filesystem_exists)

if(NOT filesystem_exists)
    if(experimental_filesystem_exists)
        message(STATUS "Header <filesystem> not available, but <experimental/filesystem> exists.")
        target_compile_definitions(core PRIVATE FILESYSTEM_IS_EXPERIMENTAL)
    else()
        message(ERROR "Neither <filesystem> nor <experimental/filesystem> exists.")
    endif()
endif()
