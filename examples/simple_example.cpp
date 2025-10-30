#include "frtclap.hpp"

#include <cassert>

struct Demo
{
    std::string input;
    std::string output;
};

int main()
{
    const char* demo_args[] = {"simple_example.exe",
                               "--input",
                               "input_file.cpp",
                               "--output",
                               "output_file"};

    auto parsed = frtclap::parse<Demo>(std::size(demo_args),
                                       const_cast<char**>(demo_args));

    assert(parsed.input == "input_file.cpp");
    assert(parsed.output == "output_file");

    return 0;
}