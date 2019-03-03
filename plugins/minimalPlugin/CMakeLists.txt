cmake_minimum_required(VERSION 3.9)

# option for finding interface

option(PLUGIN_INTERFACE_INCLUDE_DIR "Path to the interface headers.")

if(NOT EXISTS "${PLUGIN_INTERFACE_INCLUDE_DIR}/pluginExports.hpp")
    message(FATAL_ERROR "Could not find pluginExports.hpp in given plugin interface dir.")
endif()

# sources

set(source_dir src)
set(include_dir include)
set(generated_header_dir ${CMAKE_CURRENT_BINARY_DIR}/generated)

set(export_header
    ${generated_header_dir}/plugin_export.hpp)

set(headers
    ${include_dir}/minimalPlugin.hpp
    ${PLUGIN_INTERFACE_INCLUDE_DIR}/pluginExports.hpp
    ${export_header})

set(sources
    ${source_dir}/minimalPlugin.cpp)

# library

include_directories(${include_dir})
include_directories(${generated_header_dir})
include_directories(${PLUGIN_INTERFACE_INCLUDE_DIR})
add_library(minimalPlugin SHARED ${headers} ${sources})

# generate export header

include(GenerateExportHeader)
generate_export_header(minimalPlugin
    BASE_NAME minimalPlugin
    EXPORT_MACRO_NAME PLUGIN_EXPORT
    EXPORT_FILE_NAME ${export_header}
    STATIC_DEFINE PLUGIN_BUILT_AS_STATIC)
