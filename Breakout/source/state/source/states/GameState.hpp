#ifndef BREAKOUT_GAMESTATE_HPP
#define BREAKOUT_GAMESTATE_HPP

#include "GameData.hpp"
#include "State.hpp"

namespace machine
{

class GameState : public State
{
public:
    explicit GameState(::common::GameData& gameData);
    ~GameState() override;
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
#endif  // BREAKOUT_GAMESTATE_HPP
