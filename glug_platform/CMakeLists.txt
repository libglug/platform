cmake_minimum_required(VERSION 3.0)

set(VER_MAJOR 1)
set(VER_MINOR 0)
set(VER_PATCH 0)
project(
    glug_platform
    VERSION ${VER_MAJOR}.${VER_MINOR}.${VER_PATCH}
    LANGUAGES C
)
include(cmake/add_gluglib.cmake)

option(BUILD_STATIC "Build as a static library instead of shared" "OFF")

set(COM_ROOT common_headers/include/glug)
set(SRC_ROOT src)
set(INC_ROOT include/glug)

list(
    APPEND
    COMMON_SOURCE
    ${COM_ROOT}/bool.h
    ${COM_ROOT}/extern.h
    ${COM_ROOT}/import.h
    ${COM_ROOT}/namespace.h
    ${COM_ROOT}/os.h
    ${INC_ROOT}/platform.h
    ${INC_ROOT}/platform/os.h
    ${INC_ROOT}/platform/platform.h
    ${INC_ROOT}/platform/system.h
    ${INC_ROOT}/platform/version.h
    ${SRC_ROOT}/platform.c
    ${SRC_ROOT}/platform_builder.h
    ${SRC_ROOT}/platform_builder.c
    ${SRC_ROOT}/system.c
    ${SRC_ROOT}/system_builder.h
    ${SRC_ROOT}/system_builder.c
)

# NULL sources
set (NULL_ROOT ${SRC_ROOT}/null)
list(
    APPEND
    COMMON_SOURCE
    ${NULL_ROOT}/platform.h
    ${NULL_ROOT}/platform.c
    ${NULL_ROOT}/system.h
    ${NULL_ROOT}/system.c
)

# Windows sources
set(WIN32_ROOT ${SRC_ROOT}/win32)
list(
    APPEND
    WIN32_SOURCE
    ${COMMON_SOURCE}
    ${WIN32_ROOT}/platform.h
    ${WIN32_ROOT}/platform.c
    ${WIN32_ROOT}/system.h
    ${WIN32_ROOT}/system.c
)

# Mac OS sources
set(MACOS_ROOT ${SRC_ROOT}/macos)
list(
    APPEND
    MACOS_SOURCE
    ${COMMON_SOURCE}
    ${MACOS_ROOT}/platform.h
    ${MACOS_ROOT}/platform.m
    ${MACOS_ROOT}/system.h
    ${MACOS_ROOT}/system.m

)

# Linux sources
set(LINUX_ROOT ${SRC_ROOT}/linux)
set(POSIX_ROOT ${SRC_ROOT}/posix)
list(
    APPEND
    LINUX_SOURCE
    ${COMMON_SOURCE}
    ${LINUX_ROOT}/platform.h
    ${LINUX_ROOT}/platform.c
    ${LINUX_ROOT}/system.h
    ${LINUX_ROOT}/system.c
    ${POSIX_ROOT}/platform.h
    ${POSIX_ROOT}/platform.c
    ${POSIX_ROOT}/system.h
    ${POSIX_ROOT}/system.c
)

# BSD sources
set(BSD_ROOT ${SRC_ROOT}/bsd)
list(
    APPEND
    BSD_SOURCE
    ${COMMON_SOURCE}
    ${BSD_ROOT}/platform.h
    ${BSD_ROOT}/platform.c
    ${BSD_ROOT}/system.h
    ${BSD_ROOT}/system.c
    ${POSIX_ROOT}/system.h
    ${POSIX_ROOT}/system.c
)

add_gluglib(
    TARGET_NAME  ${PROJECT_NAME}
    STATIC_BUILD ${BUILD_STATIC}
    WIN32_SOURCE ${WIN32_SOURCE}
    MACOS_SOURCE ${MACOS_SOURCE}
    LINUX_SOURCE ${LINUX_SOURCE}
    BSD_SOURCE   ${BSD_SOURCE}
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
