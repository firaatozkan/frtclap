#pragma once

#include <type_traits>

namespace frtclap::detail
{
    template <typename T, T... Is>
    requires std::is_enum_v<T>
    struct enum_sequence
    {
    };

    template <typename T, std::underlying_type_t<T> Begin, std::underlying_type_t<T> Index, std::underlying_type_t<T> End, std::underlying_type_t<T>... Rest>
    struct enum_sequence_builder
        : enum_sequence_builder<T, Begin, Index + 1, End, Rest..., Index>
    {
    };

    template <typename T, std::underlying_type_t<T> Begin, std::underlying_type_t<T> End, std::underlying_type_t<T>... Rest>
    struct enum_sequence_builder<T, Begin, End, End, Rest...>
        : std::type_identity<enum_sequence<T, static_cast<T>(Rest)..., static_cast<T>(End)>>
    {
    };

    template <typename T, std::underlying_type_t<T> Begin, std::underlying_type_t<T> End>
    using make_enum_sequence = typename enum_sequence_builder<T, Begin, Begin, End>::type;

} // namespace frtclap::detail