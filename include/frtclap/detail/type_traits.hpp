#pragma once

#include <array>
#include <vector>

namespace frtclap::detail
{
    template <typename>
    struct is_vector
        : std::false_type
    {
    };

    template <typename T, typename A>
    struct is_vector<std::vector<T, A>>
        : std::true_type
    {
    };

    template <typename>
    struct is_array
        : std::false_type
    {
    };

    template <typename T, std::size_t N>
    struct is_array<std::array<T, N>>
        : std::true_type
    {
    };

    template <typename T>
    inline constexpr bool is_array_v = is_array<T>::value;

    template <typename T>
    inline constexpr bool is_vector_v = is_vector<T>::value;

} // namespace frtclap::detail
