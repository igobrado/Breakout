#ifndef BREAKOUT_TEMPLATE_HPP
#define BREAKOUT_TEMPLATE_HPP

#include <algorithm>
#include <cctype>
#include <string>

namespace temp
{
struct str_less
{
    bool operator()(const std::string& t_lhs, const std::string& t_rhs) const
    {
        return t_lhs < t_rhs;
    }

    template <
            typename LHS,
            typename RHS>
    constexpr bool operator()(const LHS& t_lhs, const RHS& t_rhs) const
    {
        return std::lexicographical_compare(t_lhs.begin(), t_lhs.end(), t_rhs.begin(), t_rhs.end());
    }
    struct is_transparent
    {
    };
};
}  // namespace temp
#endif  // BREAKOUT_TEMPLATE_HPP