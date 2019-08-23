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
    ${INC_ROOT}/platform.h
    ${INC_ROOT}/platform/os.h
    ${INC_ROOT}/platform/platform.h
    ${INC_ROOT}/platform/system.h
    ${INC_ROOT}/platform/version.h
    ${SRC_ROOT}/platform.c
    ${SRC_ROOT}/platform_platform.h
    ${SRC_ROOT}/system.c
    ${SRC_ROOT}/system_platform.h
)

# Windows sources
set(WIN32_ROOT ${SRC_ROOT}/win32)
list(
    APPEND
    WIN32_SOURCE
    ${COMMON_SOURCE}
    ${WIN32_ROOT}/platform.c
    ${WIN32_ROOT}/system.c
)

# Mac OS sources
set(MACOS_ROOT ${SRC_ROOT}/macos)
list(
    APPEND
    MACOS_SOURCE
    ${COMMON_SOURCE}
    ${MACOS_ROOT}/platform.m
    ${MACOS_ROOT}/system.m
)

# linux sources
set(LINUX_ROOT ${SRC_ROOT}/linux)
list(
    APPEND
    LINUX_SOURCE
    ${COMMON_SOURCE}
    ${LINUX_ROOT}/platform.c
)

add_gluglib(
    TARGET_NAME  ${PROJECT_NAME}
    STATIC_BUILD ${BUILD_STATIC}
    WIN32_SOURCE ${WIN32_SOURCE}
    MACOS_SOURCE ${MACOS_SOURCE}
    LINUX_SOURCE ${LINUX_SOURCE}
    WIN32_LIBS   Version
    MACOS_LIBS   Foundation
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
