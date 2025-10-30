#pragma once

#include <type_traits>

#include "frtclap/tie_as_tuple.hpp"
#include "frtclap/detail/fake_object.hpp"

namespace frtclap
{
    template <std::size_t N, typename T>
    struct field_type
    {
        using type = std::remove_cvref_t<
                        std::tuple_element_t<N, decltype(tie_as_tuple(detail::fake_object<T>()))>
                    >;
    };

    template <std::size_t N, typename T>
    using field_type_t = typename field_type<N, T>::type;

} // namespace frtclap
