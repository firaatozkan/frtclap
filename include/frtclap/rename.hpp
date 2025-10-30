#pragma once

#include "frtclap/detail/fixed_string.hpp"

namespace frtclap
{
    template <typename T, detail::fixed_string S>
    struct rename
    {
        using type = T;
        static constexpr std::string_view name = S;

        type data;

        constexpr operator T&() & noexcept
        {
            return data;
        }

        constexpr operator const T&() const& noexcept
        {
            return data;
        }

        constexpr operator volatile T&() volatile& noexcept
        {
            return data;
        }

        constexpr operator const volatile T&() const volatile& noexcept
        {
            return data;
        }

        constexpr operator T&&() && noexcept
        {
            return std::move(data);
        }
    };

    template <typename>
    struct is_rename : std::false_type {};

    template <typename T, detail::fixed_string S>
    struct is_rename<rename<T, S>> : std::true_type {};

    template <typename T>
    inline constexpr bool is_rename_v = is_rename<T>::value;

} // namespace frtclap
