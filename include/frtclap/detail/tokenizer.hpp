#pragma once

#include <span>
#include <vector>
#include <optional>
#include <stdexcept>
#include <string_view>
#include <unordered_map>

#include "frtclap/rename.hpp"
#include "frtclap/subcommand.hpp"
#include "frtclap/field_type.hpp"
#include "frtclap/field_count.hpp"
#include "frtclap/detail/parse_from_span.hpp"

namespace frtclap::detail
{
    class tokenizer
    {
    private:
        using flags_t       = std::unordered_map<std::string_view, int>;
        using options_t     = std::unordered_map<std::string_view, std::vector<std::string_view>>;
        using positionals_t = std::vector<std::string_view>;
    public:
        explicit tokenizer(std::span<std::string_view> args)
        {
            for (std::size_t i = 1; i < args.size(); ++i)
            {
                std::string_view& arg = args[i];

                if (arg.starts_with("--"))
                {
                    arg.remove_prefix(2);

                    if ((i + 1) < args.size() &&
                        !args[i + 1].starts_with("-"))
                    {
                        m_options[arg].emplace_back(args[i + 1]);
                        ++i;
                    }
                    else
                        m_flags[arg]++;
                }
                else if (arg.starts_with("-") && arg.size() > 1)
                {
                    arg.remove_prefix(1);
                    for (const char& c : arg)
                        m_flags[{&c, 1}]++;
                }
                else
                    m_positionals.emplace_back(arg);
            }
        }

        template <typename UserDefined>
        [[nodiscard]] UserDefined operator()() const
        {
            return [&] <std::size_t... Is> (std::index_sequence<Is...>)
                   {
                       return UserDefined {
                           create_field<UserDefined, Is>()...
                       };
                   }
                   (std::make_index_sequence<field_count_v<UserDefined>>{});
        }

    private:
        template <typename UserDefined, std::size_t N>
        [[nodiscard]] auto create_field() const -> field_type_t<N, UserDefined>
        {
            using FieldType = field_type_t<N, UserDefined>;

            if constexpr (is_subcommand_v<FieldType>)
                return parse_subcommand<FieldType>(m_positionals);

            else if constexpr (is_rename_v<FieldType>)
            {
                constexpr auto name = field_names<UserDefined>()[N];

                if (const auto it = m_options.find(name);
                    it != m_options.end())
                {
                    return FieldType { parse_from_span<typename FieldType::type>(it->second) };
                }
                throw std::runtime_error("Couldn't locate renamed field: \"" + std::string(name) + "\"");
            }
            else
            {
                constexpr auto name = field_names<UserDefined>()[N];

                if (const auto it = m_options.find(name);
                    it != m_options.end())
                {
                    return parse_from_span<FieldType>(it->second);
                }
                throw std::runtime_error("Couldn't locate field : \"" + std::string(name) + "\"");
            }
        }

        template <typename Subcommand>
        [[nodiscard]] static Subcommand parse_subcommand(std::span<const std::string_view> positionals)
        {
            if (!positionals.size())
                throw std::runtime_error("Positionals are empty!");

            constexpr auto names = subcommand_names<Subcommand>();

            return [&] <std::size_t... Is> (std::index_sequence<Is...>)
                   {
                       std::optional<Subcommand> out;

                       ([&] <std::size_t N>
                        {
                            using Type = subcommand_alternative_t<N, Subcommand>;

                            if (names[N] == positionals.front())
                                out = Subcommand { parse_from_span<Type>(positionals.subspan(1))};
                        }
                        .template operator()<Is>(), ...);

                       if (!out.has_value())
                           throw std::runtime_error("Couldn't parse subcommand successfully!");

                       return *out;
                   }
                   (std::make_index_sequence<subcommand_size_v<Subcommand>>{});
        }

        flags_t       m_flags;
        options_t     m_options;
        positionals_t m_positionals;
    };

} // namespace frtclap::detail