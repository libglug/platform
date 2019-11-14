add_subdirectory(cunit/CUnit EXCLUDE_FROM_ALL)
include(add_int_test.cmake)
include(add_unit_test.cmake)

set(TESTED_LIB glug_platform)
set(TEST_ROOT .)
set(SRC_ROOT ../${TESTED_LIB})

list(
    APPEND
    INCLUDE_DIRS
    CUnit/CUnit/include
    ${SRC_ROOT}/common_headers/include
    ${SRC_ROOT}/include
)

# integration test
find_package(${TESTED_LIB} REQUIRED)
add_int_test(
    TARGETNAME
        integration
    SOURCES
        integration/main.c
        create_suite.h
        create_suite.c
    INCLUDE_DIRS
        ${INCLUDE_DIRS}
    LINK_LIBS
        CUnit
        ${TESTED_LIB}
)

# unit tests
list(
    APPEND
    TEST_TARGETS
)
add_unit_test(
    TARGETNAME
        unit-system-linux
    SOURCES
        create_suite.h
        create_suite.c
        unit/linux/mocks/unistd.h
        unit/linux/mocks/unistd.c
        unit/linux/system.c
        ${SRC_ROOT}/src/system/linux/system.c
    INCLUDE_DIRS
        ${TEST_ROOT}
        ${SRC_ROOT}
        unit/linux/mocks
)

add_unit_test(
    TARGETNAME
        unit-system-win32
    SOURCES
        create_suite.h
        create_suite.c
        unit/win32/mocks/Windows.h
        unit/win32/mocks/Windows.c
        unit/win32/system.c
        ${SRC_ROOT}/src/system/win32/system.c
    INCLUDE_DIRS
        ${TEST_ROOT}
        ${SRC_ROOT}
        unit/win32/mocks
)

# create a custom target which builds tests and their dependencies
# (bug in CMake? (https://gitlab.kitware.com/cmake/cmake/issues/8774))
add_custom_target(
    check
    ALL
    DEPENDS
        CUnit integration ${TEST_TARGETS} ${TESTED_LIB}
)

# copy the CUnit library to the same directory
add_custom_command(
    TARGET
        check POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:CUnit> ${CMAKE_CURRENT_BINARY_DIR}
)

# copy the target lib for integration tests
add_custom_command(
    TARGET
        integration POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:${TESTED_LIB}> ${CMAKE_CURRENT_BINARY_DIR}
)
