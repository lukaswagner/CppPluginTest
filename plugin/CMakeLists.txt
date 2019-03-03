cmake_minimum_required(VERSION 3.9)

# sources

set(source_dir src)
set(include_dir include)
set(generated_header_dir ${CMAKE_CURRENT_BINARY_DIR}/generated)

set(export_header
    ${generated_header_dir}/plugin_export.hpp)

set(headers
    ${include_dir}/examplePlugin.hpp
    ${plugin_export_header}
    ${export_header})

set(sources
    ${source_dir}/examplePlugin.cpp)

# library

include_directories(${include_dir})
include_directories(${generated_header_dir})
include_directories(${plugin_interface_header_dir})
add_library(examplePlugin SHARED ${headers} ${sources})

# generate export header

include(GenerateExportHeader)
generate_export_header(examplePlugin
    BASE_NAME plugin
    EXPORT_MACRO_NAME PLUGIN_EXPORT
    EXPORT_FILE_NAME ${export_header}
    STATIC_DEFINE PLUGIN_BUILT_AS_STATIC)
