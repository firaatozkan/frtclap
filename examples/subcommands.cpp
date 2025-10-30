#include "frtclap.hpp"

#include <cassert>

struct accumulate_all
{
    std::vector<int> inputs;
};

struct multiply_two_integers
{
    int first;
    int second;
};

struct Demo
{
    frtclap::subcommand<accumulate_all,
                        multiply_two_integers> cmd;
};

template <typename... Ts>
struct overloaded : Ts...
{
    using Ts::operator()...;
};

int main()
{
    const char* demo_args[] = {"subcommands.exe",
                               "accumulate_all",
                               "5",
                               "4",
                               "3",
                               "2",
                               "1",
                               "0"};

    auto parsed = frtclap::parse<Demo>(std::size(demo_args),
                                       const_cast<char **>(demo_args));

    std::visit(overloaded{
                   [](const accumulate_all &a)
                   {
                       assert(a.inputs[0] == 5);
                       assert(a.inputs[1] == 4);
                       assert(a.inputs[2] == 3);
                       assert(a.inputs[3] == 2);
                       assert(a.inputs[4] == 1);
                       assert(a.inputs[5] == 0);
                   },
                   [](const multiply_two_integers &a)
                   {
                       assert(false);
                   },
               },
               parsed.cmd);

    return 0;
}