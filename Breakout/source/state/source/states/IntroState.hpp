#ifndef BREAKOUT_INTROSTATE_HPP
#define BREAKOUT_INTROSTATE_HPP

#include <SFML/Graphics.hpp>

#include "Config.hpp"
#include "GameData.hpp"
#include "State.hpp"

namespace machine
{

class IntroState : public State
{
public:
    IntroState(::common::GameData& gameData);
    /**@copydoc State::update()*/
    void update(const float deltaTime) override;

    /**@copydoc State::handleInput()*/
    void handleInput() override;

    /**@copydoc State::draw()*/
    void draw() override;

private:
    ::common::GameData& mGameData;
    sf::Sprite          mBackground;

    const float mSwapTime;
    sf::Clock   mClock;
    Config&     mStateConfig;
};

}  // namespace machine

#endif  // BREAKOUT_INTROSTATE_HPP
