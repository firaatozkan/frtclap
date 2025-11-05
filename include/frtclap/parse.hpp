#pragma once

#include <iostream>
#include "frtclap/print_help.hpp"
#include "frtclap/detail/parse.hpp"

namespace frtclap
{
    template <typename T>
    [[nodiscard]] T parse(int argc, char** argv)
    {
        std::vector<std::string_view> args(argv, argv + argc);

        try
        {
            return detail::parse<T>(args);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            print_help<T>();
            std::exit(1);
        }
    }

} // namespace frtclap
