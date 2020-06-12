#ifndef BREAKOUT_MENUSTATE_HPP
#define BREAKOUT_MENUSTATE_HPP

#include "GameData.hpp"
#include "State.hpp"

namespace machine
{

class MenuState : public State
{
public:
    explicit MenuState(::common::GameData& gameData);

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

#endif  // BREAKOUT_MENUSTATE_HPP
