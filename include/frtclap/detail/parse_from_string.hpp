#pragma once

#include <string>

#include "frtclap/magic_enums.hpp"

namespace frtclap::detail
{
    template <typename T>
    struct parse_from_string_impl
    {
        [[nodiscard]] static T apply(std::string_view input)
        {
            if constexpr (std::is_enum_v<T>)
                return frtclap::string_to_enum<T>(input);

            else
            {
                // The rest is not implemented yet
                static_assert(false);
            }
        }
    };

    template <>
    struct parse_from_string_impl<int>
    {
        [[nodiscard]] static int apply(std::string_view input)
        {
            return std::stoi(input.data());
        }
    };

    template <>
    struct parse_from_string_impl<long>
    {
        [[nodiscard]] static long apply(std::string_view input)
        {
            return std::stol(input.data());
        }
    };

    template <>
    struct parse_from_string_impl<long long>
    {
        [[nodiscard]] static long long apply(std::string_view input)
        {
            return std::stoll(input.data());
        }
    };

    template <>
    struct parse_from_string_impl<std::size_t>
    {
        [[nodiscard]] static std::size_t apply(std::string_view input)
        {
            return std::stoull(input.data());
        }
    };

    template <>
    struct parse_from_string_impl<float>
    {
        [[nodiscard]] static float apply(std::string_view input)
        {
            return std::stof(input.data());
        }
    };

    template <>
    struct parse_from_string_impl<double>
    {
        [[nodiscard]] static double apply(std::string_view input)
        {
            return std::stod(input.data());
        }
    };

    template <>
    struct parse_from_string_impl<long double>
    {
        [[nodiscard]] static long double apply(std::string_view input)
        {
            return std::stold(input.data());
        }
    };

    template <>
    struct parse_from_string_impl<std::string>
    {
        [[nodiscard]] static std::string apply(std::string_view input)
        {
            return std::string(input);
        }
    };

    template <typename T>
    [[nodiscard]] T parse_from_string(std::string_view input)
    {
        return parse_from_string_impl<T>::apply(input);
    }

} // namespace frtclap::detail
