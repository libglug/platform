# define OS variables
macro (detect_os)
    if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")

        set(GLUG_OS_WIN32 TRUE)

    elseif ("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")

        set(GLUG_OS_MACOS TRUE)

    elseif ("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")

        set(GLUG_OS_LINUX TRUE)

    elseif ("${CMAKE_SYSTEM_NAME}" STREQUAL "FreeBSD" OR "${CMAKE_SYSTEM_NAME}" STREQUAL "OpenBSD")

        set(GLUG_OS_BSD TRUE)

    endif()
endmacro()
