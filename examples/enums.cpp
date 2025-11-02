#include "frtclap.hpp"

#include <cassert>
#include <iostream>

static void enums_cstyle_example();
static void enums_strongly_typed_example();

int main()
{
    enums_cstyle_example();
    enums_strongly_typed_example();
}

// 1. C-style, weakly-typed enums
enum OptimizationLevel_1
{
    DEBUG_1,
    RELEASE_1
};

struct CompilerArgs_1
{
    std::string input;
    std::string output;
    OptimizationLevel_1 opt;
};

static void enums_cstyle_example()
{
    const char* demo_args[] = {"simple_example.exe",
                               "--input",
                               "input_file.cpp",
                               "--output",
                               "output_file",
                               "--opt",
                               "DEBUG_1"};

    auto parsed = frtclap::parse<CompilerArgs_1>(std::size(demo_args),
                                                 const_cast<char **>(demo_args));

    assert(parsed.input == "input_file.cpp");
    assert(parsed.output == "output_file");
    assert(parsed.opt == OptimizationLevel_1::DEBUG_1);
    assert(frtclap::enum_to_string(parsed.opt) == "DEBUG_1");
}

// 2. Strongly typed enums (enum classes)
enum class OptimizationLevel_2
{
    DEBUG_2,
    RELEASE_2
};

struct CompilerArgs_2
{
    std::string input;
    std::string output;
    OptimizationLevel_2 opt;
};

static void enums_strongly_typed_example()
{
    const char* demo_args[] = {"simple_example.exe",
                               "--input",
                               "input_file.cpp",
                               "--output",
                               "output_file",
                               "--opt",
                               "OptimizationLevel_2::DEBUG_2"};

    auto parsed = frtclap::parse<CompilerArgs_2>(std::size(demo_args),
                                                 const_cast<char **>(demo_args));

    assert(parsed.input == "input_file.cpp");
    assert(parsed.output == "output_file");
    assert(parsed.opt == OptimizationLevel_2::DEBUG_2);
    assert(frtclap::enum_to_string(parsed.opt) == "OptimizationLevel_2::DEBUG_2");
}