#ifndef BREAKOUT_BREAKOUT_HPP
#define BREAKOUT_BREAKOUT_HPP

#include <memory>

#include "Application.hpp"
#include "GameData.hpp"

namespace game
{

class Breakout : public Application
{
public:
    explicit Breakout(const ScreenDimensions dimensions, const char* applicationName);
    ~Breakout() override = default;
    int run() override;

protected:
    int loop() override;

private:
    std::shared_ptr<::common::GameData> mGameData;
    sf::CircleShape                     mTestShape;
};

}  // namespace game

#endif  // BREAKOUT_BREAKOUT_HPP
