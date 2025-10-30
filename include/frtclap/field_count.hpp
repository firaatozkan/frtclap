#pragma once

#include <type_traits>

namespace frtclap
{
    namespace detail
    {
        struct any_lref
        {
            template <typename U>
            constexpr operator U&() const && noexcept;
        };

        struct any_rref
        {
            template <typename U>
            constexpr operator U&&() const && noexcept;
        };

        template <typename T, std::size_t... Is>
        consteval std::size_t field_count_lref(...)
        {
            return sizeof...(Is) - 1;
        }

        template <typename T, std::size_t... Is>
        consteval auto field_count_lref(int) -> decltype(T {((void) Is, any_lref{})...}, std::size_t{})
        {
            return field_count_lref<T, Is..., sizeof...(Is)>(0);
        }

        template <typename T, std::size_t... Is>
        consteval std::size_t field_count_rref(...)
        {
            return sizeof...(Is) - 1;
        }

        template <typename T, std::size_t... Is>
        consteval auto field_count_rref(int) -> decltype(T {((void) Is, any_rref{})...}, std::size_t{})
        {
            return field_count_rref<T, Is..., sizeof...(Is)>(0);
        }

        template <typename T, bool IsCopyConstructible>
        struct field_count_selector
            : std::integral_constant<std::size_t, field_count_lref<T>(0)>
        {
        };

        template <typename T>
        struct field_count_selector<T, false>
            : std::integral_constant<std::size_t, field_count_rref<T>(0)>
        {
        };

    } // namespace frtclap::detail

    template <typename T>
    struct field_count
        : detail::field_count_selector<T, std::is_copy_constructible_v<T>>
    {
    };

    template <typename T>
    inline constexpr std::size_t field_count_v = field_count<T>::value;

} // namespace frtclap
