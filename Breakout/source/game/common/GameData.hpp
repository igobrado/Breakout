#ifndef BREAKOUT_GAMEDATA_HPP
#define BREAKOUT_GAMEDATA_HPP

#include <SFML/Graphics.hpp>

#include "ResourceHolder.hpp"
#include "Scoreboard.hpp"
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
    sf::RenderWindow& window();

    /**
     * @return Reference to state machine object.
     */
    ::machine::StateMachine& machine();

    /**
     * @return Reference to resource holder object.
     */
    ResourceHolder& resource();

    /**
     * @brief Switches current state of game to provided one.
     *
     * @note Call this method when state should be changed.
     * I.E if player loses all of his lives.
     *
     * @param stateType Type of next state
     * @param gameData Game data that is important for constructing state object.
     */
    void switchState(::machine::StateType stateType);

    /**
     * @return scaling factor relative on 1280x720 resolution.
     */
    sf::Vector2f scalingFactor() const;

    /**
     * @return Reference to scoreboard object.
     */
    Scoreboard& scoreboard();

private:
    /**
     * Used to hold lambda functions.
     * Describes possible state changes from intro to --. Shall be pass as const ref to IntroStateConfig object.
     */
    std::map<std::string, std::function<void()>> mIntroStateSwitchesCallbackMap;

    /**
     * Lambda function.
     * Describes possible state change from input to --. Shall be pass as const ref to InputStateConfig object.
     */
    std::function<void(const Player& player)> mInputStateSwitchesCallback;

    ScreenDimensions        mScreenDimensions;  ///< Current dimensions of the window.
    sf::RenderWindow        mWindow;            ///< Render window onto all content shall be drawn.
    ::machine::StateMachine mStateMachine;      ///< State machine, represents the game states, like game, into etc..
    ResourceHolder          mResourceHolder;    ///< Holds managers for all resources ( sound, font, textures)..
    const float             mScalingFactorX;    ///< Scaling factor on axis X ( window width / 1280U ).
    const float             mScalingFactorY;    ///< Scaling factor on axis Y ( window height / 720U ).

    Scoreboard mScoreboard;
};

}  // namespace common

#endif  // BREAKOUT_GAMEDATA_HPP
