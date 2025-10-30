#pragma once

#include <string>

namespace frtclap::detail
{
    template <typename T>
    struct parse_from_string_impl;

    template <>
    struct parse_from_string_impl<int>
    {
        static int apply(std::string_view input)
        {
            return std::stoi(input.data());
        }
    };

    template <>
    struct parse_from_string_impl<long>
    {
        static long apply(std::string_view input)
        {
            return std::stol(input.data());
        }
    };

    template <>
    struct parse_from_string_impl<long long>
    {
        static long long apply(std::string_view input)
        {
            return std::stoll(input.data());
        }
    };

    template <>
    struct parse_from_string_impl<std::size_t>
    {
        static std::size_t apply(std::string_view input)
        {
            return std::stoull(input.data());
        }
    };

    template <>
    struct parse_from_string_impl<float>
    {
        static float apply(std::string_view input)
        {
            return std::stof(input.data());
        }
    };

    template <>
    struct parse_from_string_impl<double>
    {
        static double apply(std::string_view input)
        {
            return std::stod(input.data());
        }
    };

    template <>
    struct parse_from_string_impl<long double>
    {
        static long double apply(std::string_view input)
        {
            return std::stold(input.data());
        }
    };

    template <>
    struct parse_from_string_impl<std::string>
    {
        static std::string apply(std::string_view input)
        {
            return std::string(input);
        }
    };

    template <typename T>
    T parse_from_string(std::string_view input)
    {
        return parse_from_string_impl<T>::apply(input);
    }

} // namespace frtclap::detail
