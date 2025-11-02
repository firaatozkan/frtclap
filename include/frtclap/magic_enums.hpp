#pragma once

#include <string_view>
#include <source_location>

namespace frtclap
{
    namespace detail
    {
        template <auto V>
        consteval std::string_view enum_name_impl()
        {
            std::string_view sv = std::source_location::current().function_name();
            constexpr std::string_view name_skip = "enum_name_impl<";
            sv.remove_prefix(sv.find(name_skip) + name_skip.size());
            sv.remove_suffix(sv.size() - sv.find_first_of(">"));

            if (sv.starts_with("(enum"))
                return "unknown";

            return sv;
        }
    }

    template <typename T>
    constexpr std::string_view enum_to_string(T input)
        requires std::is_enum_v<T>
    {
        using U = std::underlying_type_t<T>;

        return [&] <U... Is> (std::integer_sequence<U, Is...>)
               {
                   std::optional<std::string_view> sv;

                   using U = std::underlying_type_t<T>;

                   ([&] <U N>
                    {
                        if (static_cast<T>(N) == input)
                            sv = detail::enum_name_impl<static_cast<T>(N)>();
                    }
                    .template operator()<Is>(), ...);

                   return *sv;
               }
               (std::make_integer_sequence<U, 100>{});
    }

    template <typename T>
    constexpr T string_to_enum(std::string_view input)
        requires std::is_enum_v<T>
    {
        using U = std::underlying_type_t<T>;

        return [&] <U... Is> (std::integer_sequence<U, Is...>)
               {
                   using U = std::underlying_type_t<T>;

                   std::optional<T> output;

                   ([&] <U N>
                    {
                        if (detail::enum_name_impl<static_cast<T>(N)>() == input)
                            output = static_cast<T>(N);
                    }
                    .template operator()<Is>(), ...);

                   return *output;
               }
               (std::make_integer_sequence<U, 100>{});
    }
}