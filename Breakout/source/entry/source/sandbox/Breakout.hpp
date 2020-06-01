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
    int loop(float accumulator) override;

private:
    std::shared_ptr<::common::GameData> mGameData;
    sf::CircleShape                     mTestShape;
    sf::Clock                           mClock;
    static constexpr float const        sDeltaTime = 1.0f / 80.0f;
};

}  // namespace game

#endif  // BREAKOUT_BREAKOUT_HPP
