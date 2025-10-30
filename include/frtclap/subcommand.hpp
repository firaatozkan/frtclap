#pragma once

#include <variant>

namespace frtclap
{
    template <typename... Ts>
    struct subcommand : std::variant<Ts...>
    {
    };

    template <typename>
    struct subcommand_size;

    template <typename... Ts>
    struct subcommand_size<subcommand<Ts...>>
        : std::variant_size<std::variant<Ts...>>
    {
    };

    template <typename T>
    inline constexpr std::size_t subcommand_size_v = subcommand_size<T>::value;

    template <std::size_t, typename>
    struct subcommand_alternative;

    template <std::size_t N, typename... Ts>
    struct subcommand_alternative<N, subcommand<Ts...>>
        : std::variant_alternative<N, std::variant<Ts...>>
    {
    };

    template <std::size_t N, typename T>
    using subcommand_alternative_t = typename subcommand_alternative<N, T>::type;

    template <typename>
    struct is_subcommand
        : std::false_type
    {
    };

    template <typename... Ts>
    struct is_subcommand<subcommand<Ts...>>
        : std::true_type
    {
    };

    template <typename T>
    inline constexpr bool is_subcommand_v = is_subcommand<T>::value;

} // namespace frtclap
