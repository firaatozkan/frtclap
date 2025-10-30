#pragma once

namespace frtclap::detail
{
    template <typename T>
    struct wrapper
    {
        const T data;
    };

    template <typename T>
    extern const wrapper<T> do_not_use_this_object;

    template <typename T>
    consteval const T& fake_object() noexcept
    {
        return do_not_use_this_object<T>.data;
    }

} // namespace frtclap::detail
