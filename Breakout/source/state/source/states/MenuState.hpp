#ifndef BREAKOUT_MENUSTATE_HPP
#define BREAKOUT_MENUSTATE_HPP

#include "State.hpp"
#include "GameData.hpp"

namespace machine
{

class MenuState : public State
{
public:
    explicit MenuState(::common::GameData& gameData);
    ~MenuState() override;
    void update(const float deltaTime) override;
    void handleInput() override;
    void draw() override;

protected:
    void onMouseKeyPressed(const sf::Mouse::Button button);
private:
    ::common::GameData& mGameData;
};

}

#endif  // BREAKOUT_MENUSTATE_HPP
