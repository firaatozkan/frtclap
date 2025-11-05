#pragma once

#include <array>
#include <string_view>
#include <source_location>

#include "frtclap/rename.hpp"
#include "frtclap/field_count.hpp"
#include "frtclap/tie_as_tuple.hpp"
#include "frtclap/detail/fake_object.hpp"

namespace frtclap
{
    namespace detail
    {
        template <auto Ptr>
        [[nodiscard]] consteval std::string_view field_name_impl() noexcept
        {
            std::string_view sv = std::source_location::current().function_name();
            sv.remove_suffix(sv.size() - sv.find_last_of(">"));
            sv.remove_prefix(sv.find_last_of(">") + 1);
            return sv;
        }

        template <typename UserDefined, std::size_t N, typename = field_type_t<N, UserDefined>>
        struct field_name
        {
            static constexpr std::string_view value = field_name_impl< &std::get<N>(frtclap::tie_as_tuple(fake_object<UserDefined>())) >();
        };

        template <typename UserDefined, std::size_t N, typename T, fixed_string S>
        struct field_name<UserDefined, N, rename<T, S>>
        {
            static constexpr std::string_view value = S;
        };

    } // namespace frtclap::detail

    template <typename T>
    [[nodiscard]] consteval auto field_names() noexcept
    {
        return [] <std::size_t... Is> (std::index_sequence<Is...>)
               {
                   return std::array {
                       detail::field_name<T, Is>::value...
                   };
               }
               (std::make_index_sequence<field_count_v<T>>{});
    }

} // namespace frtclap
