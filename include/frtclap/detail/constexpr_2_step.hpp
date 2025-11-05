#pragma once

namespace frtclap::detail
{
    template <auto Lambda, std::size_t Cap>
    [[nodiscard]] constexpr auto constexpr_2_step()
    {
        constexpr auto oversized = []
                                   {
                                       const auto output = Lambda();

                                       const std::size_t size_ = std::ranges::size(output);

                                       auto oversized_ = std::array<std::ranges::range_value_t<decltype(output)>,
                                                                    Cap>{};

                                       std::ranges::copy(output, oversized_.begin());

                                       return std::pair{oversized_, size_};
                                   }
                                   ();

        constexpr auto rightsized = [&]
                                    {
                                        auto rightsized_ = std::array<typename decltype(oversized.first)::value_type,
                                                                      oversized.second>{};

                                        const auto begin = oversized.first.begin();
                                        const auto end = std::next(oversized.first.begin(), oversized.second);
                                        std::copy(begin, end, rightsized_.begin());

                                        return rightsized_;
                                    }
                                    ();

        return rightsized;
    }

} // namespace frtclap::detail