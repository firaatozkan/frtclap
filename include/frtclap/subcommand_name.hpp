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
        template <typename>
        consteval std::string_view subcommand_name_impl()
        {
            constexpr std::string_view first_skip = "subcommand_name_impl<";
            constexpr std::string_view second_skip = ">(void)";

            std::string_view sv = std::source_location::current().function_name();            
            sv.remove_prefix(sv.find(first_skip) + first_skip.size());
            sv.remove_suffix(sv.size() - sv.find(second_skip));

            if (sv.starts_with("class "))
                sv.remove_prefix(6);
            else if (sv.starts_with("struct "))
                sv.remove_prefix(7);

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

    } // namespace detail

    template <typename Subcommand>
    consteval auto subcommand_names()
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
