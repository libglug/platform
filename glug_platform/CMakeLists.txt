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
set(INC_ROOT include/glug)
set(SRC_ROOT src)
set(PLAT_ROOT ${SRC_ROOT}/platform)
set(SYS_ROOT ${SRC_ROOT}/system)

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
    ${INC_ROOT}/platform/version_t.h
    ${PLAT_ROOT}/platform.c
    ${PLAT_ROOT}/platform_builder.h
    ${PLAT_ROOT}/platform_builder_null.c
    ${PLAT_ROOT}/platform_builder_win32.c
    ${PLAT_ROOT}/platform_builder_macos.c
    ${PLAT_ROOT}/platform_builder_linux.c
    ${PLAT_ROOT}/platform_builder_bsd.c
    ${SYS_ROOT}/system.c
    ${SYS_ROOT}/system_builder.h
    ${SYS_ROOT}/system_builder_null.c
    ${SYS_ROOT}/system_builder_win32.c
    ${SYS_ROOT}/system_builder_macos.c
    ${SYS_ROOT}/system_builder_linux.c
    ${SYS_ROOT}/system_builder_bsd.c
)

# NULL sources
set (NULL_PLAT_ROOT ${PLAT_ROOT}/null)
set (NULL_SYS_ROOT ${SYS_ROOT}/null)
list(
    APPEND
    COMMON_SOURCE
    ${NULL_PLAT_ROOT}/platform.h
    ${NULL_PLAT_ROOT}/platform.c
    ${NULL_SYS_ROOT}/system.h
    ${NULL_SYS_ROOT}/system.c
)

# Windows sources
set(WIN32_PLAT_ROOT ${PLAT_ROOT}/win32)
set(WIN32_SYS_ROOT ${SYS_ROOT}/win32)
list(
    APPEND
    WIN32_SOURCE
    ${COMMON_SOURCE}
    ${WIN32_PLAT_ROOT}/platform.h
    ${WIN32_PLAT_ROOT}/platform.c
    ${WIN32_SYS_ROOT}/system.h
    ${WIN32_SYS_ROOT}/system.c
)

# Mac OS sources
set(MACOS_PLAT_ROOT ${PLAT_ROOT}/macos)
set(MACOS_SYS_ROOT ${SYS_ROOT}/macos)
list(
    APPEND
    MACOS_SOURCE
    ${COMMON_SOURCE}
    ${MACOS_PLAT_ROOT}/platform.h
    ${MACOS_PLAT_ROOT}/platform.m
    ${MACOS_SYS_ROOT}/system.h
    ${MACOS_SYS_ROOT}/system.m
)

# Linux sources
set(LINUX_PLAT_ROOT ${PLAT_ROOT}/linux)
set(LINUX_SYS_ROOT ${SYS_ROOT}/linux)
list(
    APPEND
    LINUX_SOURCE
    ${COMMON_SOURCE}
    ${LINUX_PLAT_ROOT}/platform.h
    ${LINUX_PLAT_ROOT}/platform.c
    ${LINUX_SYS_ROOT}/system.h
    ${LINUX_SYS_ROOT}/system.c
)

# BSD sources
set(BSD_PLAT_ROOT ${PLAT_ROOT}/bsd)
set(BSD_SYS_ROOT ${SYS_ROOT}/bsd)
list(
    APPEND
    BSD_SOURCE
    ${COMMON_SOURCE}
    ${BSD_PLAT_ROOT}/platform.h
    ${BSD_PLAT_ROOT}/platform.c
    ${BSD_SYS_ROOT}/system.h
    ${BSD_SYS_ROOT}/system.c
)

add_gluglib(
    TARGET_NAME  ${PROJECT_NAME}
    STATIC_BUILD ${BUILD_STATIC}
    WIN32_SOURCE ${WIN32_SOURCE}
    MACOS_SOURCE ${MACOS_SOURCE}
    LINUX_SOURCE ${LINUX_SOURCE}
    BSD_SOURCE   ${BSD_SOURCE}
    WIN32_LIBS
    MACOS_LIBS   Foundation
    LINUX_LIBS   dl
    BSD_LIBS
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
