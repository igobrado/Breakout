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
    ::common::GameData& mGameData;    ///< Reference to  shared game data(Resource holder etc..)
    sf::Sprite          mBackground;  ///< Background of the state.
};

}  // namespace machine

#endif  // BREAKOUT_ENDSTATE_HPP
