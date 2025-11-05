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

#if defined(_MSC_VER) && !defined(__clang__)
            constexpr std::string_view begin_skip = "class std::basic_string_view<char,struct std::char_traits<char> > __cdecl frtclap::detail::field_name_impl<";
            constexpr std::string_view end_skip = ">(void) noexcept";
            constexpr std::string_view backward = "->";
#elif defined(__clang__)
            constexpr std::string_view begin_skip = "std::string_view frtclap::detail::field_name_impl() [Ptr = ";
            constexpr std::string_view end_skip = "]";
            constexpr std::string_view backward = ".";
#elif defined(__GNUC__)
            constexpr std::string_view begin_skip = "consteval std::string_view frtclap::detail::field_name_impl() [with auto Ptr = (& do_not_use_this_object<";
            constexpr std::string_view end_skip = "); std::string_view = std::basic_string_view<char>]";
            constexpr std::string_view backward = "::";
#endif
            sv.remove_prefix(begin_skip.size());
            sv.remove_suffix(end_skip.size());
            sv.remove_prefix(sv.rfind(backward) + backward.size());
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
