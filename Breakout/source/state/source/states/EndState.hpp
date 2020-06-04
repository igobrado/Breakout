#ifndef BREAKOUT_ENDSTATE_HPP
#define BREAKOUT_ENDSTATE_HPP

#include "State.hpp"
#include "GameData.hpp"

namespace machine
{

class EndState : public State
{
public:
    explicit EndState(::common::GameData& gameData);
    ~EndState() override;

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

#endif  // BREAKOUT_ENDSTATE_HPP
