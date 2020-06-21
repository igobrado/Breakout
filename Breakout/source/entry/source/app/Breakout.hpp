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
    std::shared_ptr<::common::GameData> mGameData;                  ///< Shared ptr to game common data
    sf::Clock                           mClock;                     ///< Clock to calculate frame time.
    static constexpr float const        sDeltaTime = 1.0f / 80.0f;  ///< Fixed delta time to slow down the game loop.
};

}  // namespace game

#endif  // BREAKOUT_BREAKOUT_HPP
