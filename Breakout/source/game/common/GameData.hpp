#ifndef BREAKOUT_GAMEDATA_HPP
#define BREAKOUT_GAMEDATA_HPP

#include <SFML/Graphics.hpp>

struct ScreenDimensions
{
    std::uint32_t width;
    std::uint32_t height;
};

namespace common
{
class GameData
{
public:
    explicit GameData(const ScreenDimensions dimensions, const char* applicationName);
    sf::RenderWindow& window();

private:
    const ScreenDimensions mScreenDimensions;
    sf::RenderWindow       mWindow;
};

}  // namespace common

#endif  // BREAKOUT_GAMEDATA_HPP
