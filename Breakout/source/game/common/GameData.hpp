#ifndef BREAKOUT_GAMEDATA_HPP
#define BREAKOUT_GAMEDATA_HPP

#include <SFML/Graphics.hpp>

#include "ResourceHolder.hpp"
#include "ScreenDimensions.hpp"
#include "StateMachine.hpp"

namespace common
{
/**
 * @brief Shared context across state classes.
 * 
 * Holds relevant data for every state.
 * I.E. application name, screen dimensions, state machine etc...
 */
class GameData
{
public:
    explicit GameData(const char* applicationName);

    /**
     * @return Reference to main window object.
     */
    sf::RenderWindow&        window();

    /**
     * @return Reference to state machine object.
     */
    ::machine::StateMachine& machine();

    /**
     * @return Reference to resource holder object.
     */
    ResourceHolder&          resource();

    /**
     * @brief Switches current state of game to provided one.
     *
     * @note Call this method when state should be changed.
     * I.E if player loses all of his lives.
     *
     * @param stateType Type of next state
     * @param gameData Game data that is important for constructing state object.
     */
    void                     switchState(::machine::StateType stateType, GameData& gameData);

private:
    const ScreenDimensions  mScreenDimensions;
    sf::RenderWindow        mWindow;
    ::machine::StateMachine mStateMachine;
    ResourceHolder          mResourceHolder;
};

}  // namespace common

#endif  // BREAKOUT_GAMEDATA_HPP
