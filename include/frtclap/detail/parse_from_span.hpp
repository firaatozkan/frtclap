#pragma once

#include "frtclap/rename.hpp"
#include "frtclap/detail/type_traits.hpp"
#include "frtclap/detail/parse_from_string.hpp"

namespace frtclap::detail
{
    template <typename T>
    struct parse_from_span_impl
    {
        [[nodiscard]] static T apply(std::span<const std::string_view> input)
        {
            constexpr std::size_t field_count_ = field_count_v<T>;

            constexpr bool has_container = [&] <std::size_t... Is> (std::index_sequence<Is...>)
                                           {
                                               bool output = false;

                                               ([&]
                                                {
                                                    if constexpr (is_container_v<field_type_t<Is, T>>)
                                                    {
                                                        if constexpr (Is != field_count_ - 1)
                                                            throw std::runtime_error("Container has to be the last element!");

                                                        output = true;
                                                    }
                                                }
                                                (), ...);

                                               return output;
                                           }
                                           (std::make_index_sequence<field_count_>{});

            if constexpr (has_container)
            {
                return [&] <std::size_t... Is> (std::index_sequence<Is...>)
                       {
                           return T {
                              parse_from_string<field_type_t<Is, T>>(input[Is])...,
                              parse_from_span<field_type_t<field_count_ - 1, T>>(input.subspan(field_count_ - 1))
                           };
                       }
                       (std::make_index_sequence<field_count_ - 1>{});
            }
            else
            {
                if (field_count_ != input.size())
                    throw std::runtime_error("Input count does not match field count!");

                return [&] <std::size_t... Is> (std::index_sequence<Is...>)
                       {
                           return T {
                               parse_from_string<field_type_t<Is, T>>(input[Is])...
                           };
                       }
                       (std::make_index_sequence<field_count_v<T>>{});
            }
        }
    };

    template <typename T, fixed_string S>
    struct parse_from_span_impl<rename<T, S>>
    {
        [[nodiscard]] static rename<T, S> apply(std::span<const std::string_view> input)
        {
            return rename<T, S> {parse_from_span_impl<T>::apply(input)};
        }
    };

    template <>
    struct parse_from_span_impl<std::string>
    {
        [[nodiscard]] static std::string apply(std::span<const std::string_view> input)
        {
            if (!input.size())
                throw std::runtime_error("Input is empty!");

            std::string out = parse_from_string<std::string>(input.front());

            for (std::size_t i = 1; i < input.size(); ++i)
                out += ", " + parse_from_string<std::string>(input[i]);

            return out;
        }
    };

    template <typename T, typename A>
    struct parse_from_span_impl<std::vector<T, A>>
    {
        [[nodiscard]] static std::vector<T, A> apply(std::span<const std::string_view> input)
        {
            std::vector<T, A> out;
            out.reserve(input.size());

            for (const auto& i : input)
                out.emplace_back(parse_from_string<T>(i));

            return out;
        }
    };

    template <typename T, std::size_t N>
    struct parse_from_span_impl<std::array<T, N>>
    {
        [[nodiscard]] static std::array<T, N> apply(std::span<const std::string_view> input)
        {
            std::array<T, N> out;
            if (input.size() != N)
                throw std::runtime_error("Input count does not match the array size!");

            for (std::size_t i = 0; i < input.size(); ++i)
                out[i] = parse_from_string<T>(input[i]);

            return out;
        }
    };

    template <typename T>
    [[nodiscard]] T parse_from_span(std::span<const std::string_view> input)
    {
        return parse_from_span_impl<T>::apply(input);
    }

} // namespace frtclap::detail
