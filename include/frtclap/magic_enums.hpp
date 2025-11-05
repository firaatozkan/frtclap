#pragma once

#include <stdexcept>
#include <string_view>
#include <source_location>

#include "frtclap/detail/enum_sequence.hpp"
#include "frtclap/detail/constexpr_2_step.hpp"

namespace frtclap
{
    template <typename T>
    requires std::is_enum_v<T>
    struct enum_range
    {
        static constexpr int min = -128;
        static constexpr int max = 216;
    };

    namespace detail
    {
        template <auto V>
        [[nodiscard]] consteval std::string_view enum_name_impl()
        {
            std::string_view sv = std::source_location::current().function_name();
            constexpr std::string_view name_skip = "enum_name_impl<";
            sv.remove_prefix(sv.find(name_skip) + name_skip.size());
            sv.remove_suffix(sv.size() - sv.find_first_of(">"));

            if (sv.starts_with("(enum"))
                return "<unknown>";

            return sv;
        }

        template <typename T>
        [[nodiscard]] constexpr std::vector<std::pair<T, std::string_view>> enum_names_vector()
            requires std::is_enum_v<T>
        {
            std::vector<std::pair<T, std::string_view>> output;

            [&] <T... Is> (enum_sequence<T, Is...>)
            {
                using T2 = T;

                ([&] <T2 N>
                 {
                     constexpr auto name = enum_name_impl<N>();
                     if (name != "<unknown>")
                         output.emplace_back(N, name);
                 }
                 .template operator()<Is>(), ...);
            }
            (make_enum_sequence<T,
                                static_cast<std::underlying_type_t<T>>(enum_range<T>::min),
                                static_cast<std::underlying_type_t<T>>(enum_range<T>::max)>{});

            return output;
        }

        template <typename T, std::size_t N>
        requires std::is_enum_v<T>
        struct enum_map
        {
            std::array<std::pair<T, std::string_view>, N> data;

            consteval enum_map(const std::array<std::pair<T, std::string_view>, N>& input)
                : data(input)
            {
            }

            [[nodiscard]] constexpr std::string_view operator[](T input) const
            {
                const auto it = std::find_if(data.begin(),
                                             data.end(),
                                             [=] (const auto& p)
                                             {
                                                 return p.first == input;
                                             });

                if (it != data.end())
                    return it->second;

                throw std::range_error("Enum value not found!");
            }

            [[nodiscard]] constexpr T operator[](std::string_view input) const
            {
                const auto it = std::find_if(data.begin(),
                                             data.end(),
                                             [=] (const auto& p)
                                             {
                                                 return p.second == input;
                                             });

                if (it != data.end())
                    return it->first;

                throw std::range_error("Enum value not found!");
            }

            [[nodiscard]] constexpr auto begin() const noexcept
            {
                return data.begin();
            }

            [[nodiscard]] constexpr auto end() const noexcept
            {
                return data.end();
            }
        };

        template <typename T, std::size_t Cap = 255>
        [[nodiscard]] constexpr auto make_enum_map()
            requires std::is_enum_v<T>
        {
            static_assert(Cap <= 255, "Does not support enum entries more than 255");
            return detail::enum_map(detail::constexpr_2_step<[] { return detail::enum_names_vector<T>(); }, Cap>());
        }

    } // namespace frtclap::detail

    template <typename T>
    inline constexpr auto enum_map = detail::make_enum_map<T>();

    template <typename T>
    [[nodiscard]] constexpr std::string_view enum_to_string(T input)
        requires std::is_enum_v<T>
    {
        return enum_map<T>[input];
    }

    template <typename T>
    [[nodiscard]] constexpr T string_to_enum(std::string_view input)
        requires std::is_enum_v<T>
    {
        return enum_map<T>[input];
    }

} // namespace frtclap