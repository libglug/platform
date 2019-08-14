# create simple example with simple dependencies
function (add_example)
    set(SINGLE_VALS TARGET_NAME LINK_LIB INSTALL_PATH)
    set(MULTI_VALS SRCS)
    cmake_parse_arguments(GLUG "" "${SINGLE_VALS}" "${MULTI_VALS}" ${ARGN})

    set(GLUG_XMPL_NAME ${GLUG_TARGET_NAME})

    add_executable(${GLUG_XMPL_NAME} ${PLATFORM} ${GLUG_SRCS})
    target_link_libraries(${GLUG_XMPL_NAME} ${GLUG_LINK_LIB})

    set_target_properties(
        ${GLUG_XMPL_NAME}
        PROPERTIES
            INSTALL_RPATH "$ORIGIN;@loader_path"
            BUILD_WITH_INSTALL_RPATH TRUE
    )

endfunction()
