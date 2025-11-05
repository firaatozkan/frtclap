
function(run_test name)
    add_executable(${name} ${name}.cpp)
    target_include_directories(${name} PRIVATE ${PROJECT_SOURCE_DIR}/include)

    add_custom_command(
        TARGET ${name}
        POST_BUILD
        COMMAND ${name}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Running ${name}..."
    )
endfunction()

run_test(simple_example)
run_test(rename)
run_test(subcommands)
run_test(enums)
