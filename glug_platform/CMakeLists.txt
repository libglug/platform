cmake_minimum_required(VERSION 3.0)

set(VER_MAJOR 1)
set(VER_MINOR 0)
set(VER_PATCH 0)
project(glug_platform VERSION ${VER_MAJOR}.${VER_MINOR}.${VER_PATCH})
include(cmake/add_gluglib.cmake)

option(BUILD_STATIC "Build as a static library instead of shared" "OFF")

set(SRC_ROOT src)
set(INC_ROOT include/glug)

list(
    APPEND
    COMMON_SOURCE
    # add common source files
)

# Windows sources
list(
    APPEND
    WIN32_SOURCE
    ${COMMON_SOURCE}
    # add win32 specific source files
)

# Mac OS sources
list(
    APPEND
    MACOS_SOURCE
    ${COMMON_SOURCE}
    # add macos specific source files
)

# linux sources
list(
    APPEND
    LINUX_SOURCE
    ${COMMON_SOURCE}
    # add linux specific source files
)

add_gluglib(
    TARGET_NAME  ${PROJECT_NAME}
    STATIC_BUILD ${BUILD_STATIC}
    WIN32_SOURCE ${WIN32_SOURCE}
    MACOS_SOURCE ${MACOS_SOURCE}
    LINUX_SOURCE ${LINUX_SOURCE}
    WIN32_LIBS
    MACOS_LIBS
    LINUX_LIBS
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/common_headers/include>
    INTERFACE
        $<INSTALL_INTERFACE:include>
)

# install the library
install(
    TARGETS
        ${PROJECT_NAME}
    EXPORT
        Find${PROJECT_NAME}
    DESTINATION
        lib
)

#install the lib's headers
install(
    DIRECTORY
        include/
    DESTINATION
        include
)

# install the common_headers
install(
    DIRECTORY
        common_headers/include/
    DESTINATION
        include
    FILES_MATCHING PATTERN
        "*.h"
)

# export the package to be included in other projects
export(PACKAGE ${PROJECT_NAME})
export(
    TARGETS
        ${PROJECT_NAME}
    FILE
        ${PROJECT_NAME}-config.cmake
)

# install export file
install(
    EXPORT
        Find${PROJECT_NAME}
    DESTINATION
        cmake
)
