cmake_minimum_required(VERSION 3.9)

# project settings

project(plugin_test CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# add core

add_subdirectory(core)

# set the interface path - when writing a plugin, this would be set as cmake option

set(PLUGIN_INTERFACE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/interface CACHE PATH "Path to the interface headers.")

# add the plugins - the macro copies the results to a single plugin dir

set(plugin_dir ${CMAKE_BINARY_DIR}/plugins_out)
if(NOT EXISTS ${plugin_dir})
    file(MAKE_DIRECTORY ${plugin_dir})
endif()

macro(copy_results target)
    add_custom_command(
        OUTPUT ${plugin_dir}/${target}
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${target}> ${plugin_dir}/
        DEPENDS ${target})
    add_custom_target(copy_${target} ALL
        DEPENDS ${plugin_dir}/${target})
endmacro()

add_subdirectory(plugins/minimalPlugin)
copy_results(minimalPlugin)

add_subdirectory(plugins/dependencyPlugin)
copy_results(dependencyPlugin)

add_subdirectory(plugins/dependentPlugin)
copy_results(dependentPlugin)
