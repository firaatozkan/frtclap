#pragma once

#include <array>
#include <string_view>
#include <source_location>

#include "frtclap/rename.hpp"
#include "frtclap/subcommand.hpp"

namespace frtclap
{
    namespace detail
    {
        template <typename T>
        [[nodiscard]] consteval std::string_view subcommand_name_impl() noexcept
        {
            std::string_view sv = std::source_location::current().function_name();

#if defined(_MSC_VER) && !defined(__clang__)
            constexpr std::string_view begin_skip = "class std::basic_string_view<char,struct std::char_traits<char> > __cdecl frtclap::detail::subcommand_name_impl<";
            constexpr std::string_view end_skip = ">(void) noexcept";
#elif defined(__clang__)
            constexpr std::string_view begin_skip = "std::string_view frtclap::detail::subcommand_name_impl() [T = ";
            constexpr std::string_view end_skip = "]";
#elif defined(__GNUC__)
            constexpr std::string_view begin_skip = "consteval std::string_view frtclap::detail::subcommand_name_impl() [with T = ";
            constexpr std::string_view end_skip = "; std::string_view = std::basic_string_view<char>]";
#endif
            sv.remove_prefix(begin_skip.size());
            sv.remove_suffix(end_skip.size());

            if (sv.starts_with("struct "))
                sv.remove_prefix(7);
            else if (sv.starts_with("class "))
                sv.remove_prefix(6);

            return sv;
        }

        template <typename T>
        struct subcommand_name
        {
            static constexpr std::string_view value = subcommand_name_impl<T>();
        };

        template <typename T, fixed_string S>
        struct subcommand_name<rename<T, S>>
        {
            static constexpr std::string_view value = S;
        };

    } // namespace frtclap::detail

    template <typename Subcommand>
    [[nodiscard]] consteval auto subcommand_names()
    {
        return [] <std::size_t... Is> (std::index_sequence<Is...>)
               {
                   return std::array {
                       detail::subcommand_name<subcommand_alternative_t<Is, Subcommand>>::value...
                   };
               }
               (std::make_index_sequence<subcommand_size_v<Subcommand>>{});
    }

} // namespace frtclap
