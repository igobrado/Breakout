#ifndef BREAKOUT_SCREENDIMENSIONS_HPP
#define BREAKOUT_SCREENDIMENSIONS_HPP

#include <cstdint>

struct ScreenDimensions
{
    std::uint32_t width;
    std::uint32_t height;
};

/**
 * @brief Screen dimensions.
 *
 * @note Shall NOT be used for data processing and any ANY kind of callculation!
 */
constexpr const ScreenDimensions sScreenDimensions = ScreenDimensions{ 1280U, 720U };


#endif  // BREAKOUT_SCREENDIMENSIONS_HPP
