#pragma once

#include <string_view>

namespace frtclap::detail
{
    template <std::size_t N>
    struct fixed_string
    {
        char data[N - 1];
        static constexpr std::size_t size = N - 1;

        consteval fixed_string(const char (&str)[N]) noexcept
        {
            for (std::size_t i = 0; i < N - 1; ++i)
                data[i] = str[i];
        }

        consteval operator std::string_view() const noexcept
        {
            return std::string_view(data, size);
        }
    };

} // namespace frtclap::detail
