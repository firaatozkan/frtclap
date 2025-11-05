#pragma once

#include "frtclap/detail/tokenizer.hpp"

namespace frtclap::detail
{
    template <typename T>
    [[nodiscard]] T parse(std::span<std::string_view> args)
    {
        const tokenizer tk(args);
        return tk.template operator()<T>();
    }

} // namespace frtclap::detail
