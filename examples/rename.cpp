#include "frtclap.hpp"

#include <cassert>

static void rename_options_example();
static void rename_subcommands_example();

int main()
{
    rename_options_example();
    rename_subcommands_example();
    return 0;
}


// 1. Rename usage with options
struct Demo_1
{
    frtclap::rename<std::string, "my_input"> input;
    frtclap::rename<std::string, "my_output"> output;
};

static void rename_options_example()
{
    const char *demo_args[] = {"simple_example.exe",
                               "--my_input",
                               "input_file.cpp",
                               "--my_output",
                               "output_file"};

    auto parsed = frtclap::parse<Demo_1>(std::size(demo_args),
                                         const_cast<char**>(demo_args));

    assert(static_cast<const std::string &>(parsed.input) == "input_file.cpp");
    assert(static_cast<const std::string &>(parsed.output) == "output_file");
}


// 2. Rename usage with subcommands
struct create
{
    std::string filename;
};

struct _delete
{
    std::string filename;
};

struct Demo_2
{
    frtclap::subcommand<create,
                        frtclap::rename<_delete, "delete">> cmd;
};

template <typename... Ts>
struct overloaded : Ts...
{
    using Ts::operator()...;
};

static void rename_subcommands_example()
{
    const char *demo_args[] = {"simple_example.exe",
                               "delete",
                               "file_to_be_deleted.txt"};

    auto parsed = frtclap::parse<Demo_2>(std::size(demo_args),
                                         const_cast<char**>(demo_args));

    std::visit(overloaded{[] (const create& c)
                          {
                              assert(false);
                          },
                          [] (const _delete& d)
                          {
                              assert(d.filename == "file_to_be_deleted.txt");
                          }},
               parsed.cmd);
}