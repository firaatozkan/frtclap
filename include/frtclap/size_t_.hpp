#pragma once

#include <type_traits>

namespace frtclap
{
    template <std::size_t N>
    using size_t_ = std::integral_constant<std::size_t, N>;

} // namespace frtclap
