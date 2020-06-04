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

    /**@copydoc State::update()*/
    void update(const float deltaTime) override;

    /**@copydoc State::handleInput()*/
    void handleInput() override;

    /**@copydoc State::draw()*/
    void draw() override;

protected:
    /***
     * @brief Handles mouse key events.
     * @param button ButtonID that was being pressed.
     */
    void onMouseKeyPressed(const sf::Mouse::Button button);
private:
    ::common::GameData& mGameData;
};

}

#endif  // BREAKOUT_MENUSTATE_HPP
