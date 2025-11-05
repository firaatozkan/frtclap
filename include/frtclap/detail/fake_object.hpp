#pragma once

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wundefined-internal"
#   pragma clang diagnostic ignored "-Wundefined-var-template"
#endif

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
    [[nodiscard]] consteval const T& fake_object() noexcept
    {
        return do_not_use_this_object<T>.data;
    }

} // namespace frtclap::detail

#ifdef __clang__
#   pragma clang diagnostic pop
#endif
