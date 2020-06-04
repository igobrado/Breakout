#ifndef BREAKOUT_INTROSTATE_HPP
#define BREAKOUT_INTROSTATE_HPP

#include "GameData.hpp"
#include "State.hpp"

namespace machine
{

class IntroState : public State
{
public:
    explicit IntroState(::common::GameData& gameData);
    ~IntroState() override;

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

}  // namespace machine

#endif  // BREAKOUT_INTROSTATE_HPP
