#ifndef BREAKOUT_INPUTSTATE_HPP
#define BREAKOUT_INPUTSTATE_HPP

#include "Config.hpp"
#include "GameData.hpp"
#include "LevelStack.hpp"
#include "State.hpp"
#include "private/Textbox.hpp"

namespace machine
{

class InputState : public State
{
public:
    explicit InputState(::common::GameData& gameData);

    /**@copydoc State::update()*/
    void update(const float deltaTime) override;

    /**@copydoc State::handleInput()*/
    void handleInput() override;

    /**@copydoc State::draw()*/
    void draw() override;

private:
    ::common::GameData& mGameData;    ///< Reference to  shared game data(Resource holder etc..)
    sf::Sprite          mBackground;  ///< Background of the state.
    Config&             mConfig;      ///< Reference to config file that game data holds.
};

}  // namespace machine
#endif  // BREAKOUT_INPUTSTATE_HPP
