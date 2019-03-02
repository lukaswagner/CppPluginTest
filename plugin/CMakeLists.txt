cmake_minimum_required(VERSION 3.9)

# sources

set(source_dir src)
set(include_dir include)
set(interface_dir ../core/interface)
set(generated_header_dir ${CMAKE_BINARY_DIR}/generated)

set(export_header
    ${generated_header_dir}/examplePlugin_export.hpp)

set(headers
    ${include_dir}/examplePlugin.hpp
    ${export_header})

set(sources
    ${source_dir}/examplePlugin.cpp)

# library

include_directories(${include_dir})
include_directories(${interface_dir})
add_library(examplePlugin SHARED ${headers} ${sources})

include(GenerateExportHeader)
generate_export_header(examplePlugin
    BASE_NAME examplePlugin
    EXPORT_MACRO_NAME EXAMPLEPLUGIN_EXPORT
    EXPORT_FILE_NAME ${export_header}
    STATIC_DEFINE EXAMPLEPLUGIN_BUILT_AS_STATIC)
