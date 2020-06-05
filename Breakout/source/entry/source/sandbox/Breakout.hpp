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
    explicit Breakout(const char* applicationName);
    ~Breakout() override = default;
    /**@copydoc Application::run**/
    int run() override;

private:
    std::shared_ptr<::common::GameData> mGameData;
    sf::Sprite                          mTestShape;
    sf::Clock                           mClock;
    static constexpr float const        sDeltaTime = 1.0f / 80.0f;
};

}  // namespace game

#endif  // BREAKOUT_BREAKOUT_HPP
