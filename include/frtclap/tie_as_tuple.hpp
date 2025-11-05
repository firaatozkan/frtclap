#pragma once

#include "frtclap/field_count.hpp"
#include "frtclap/detail/tie_as_tuple_generated.hpp"

namespace frtclap
{
    template <typename T>
    [[nodiscard]] constexpr auto tie_as_tuple(T& val) noexcept
    {
        return detail::tie_as_tuple(val,
                                    size_t_<field_count_v<T>>{});
    }
} // namespace frtclap
