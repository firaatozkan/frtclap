
add_executable(simple_example simple_example.cpp)

target_include_directories(
    simple_example
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(rename rename.cpp)

target_include_directories(
    rename
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(subcommands subcommands.cpp)

target_include_directories(
    subcommands
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)