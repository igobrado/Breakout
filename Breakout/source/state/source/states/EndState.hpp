#ifndef BREAKOUT_ENDSTATE_HPP
#define BREAKOUT_ENDSTATE_HPP

#include "GameData.hpp"
#include "State.hpp"

namespace machine
{

class EndState : public State
{
public:
    explicit EndState(::common::GameData& gameData);

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

#endif  // BREAKOUT_ENDSTATE_HPP
