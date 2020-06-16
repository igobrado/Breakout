#ifndef BREAKOUT_SCOREBOARDSTATE_HPP
#define BREAKOUT_SCOREBOARDSTATE_HPP

#include "GameData.hpp"
#include "State.hpp"

namespace machine
{

class ScoreboardState : public State
{
public:
    explicit ScoreboardState(::common::GameData& gameData);

    /**@copydoc State::update()*/
    void update(const float deltaTime) override;

    /**@copydoc State::handleInput()*/
    void handleInput() override;

    /**@copydoc State::draw()*/
    void draw() override;

private:
    ::common::GameData& mGameData;
    sf::Sprite          mBackground;
};

}  // namespace machine

#endif  // BREAKOUT_SCOREBOARDSTATE_HPP