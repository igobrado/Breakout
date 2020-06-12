#ifndef BREAKOUT_STATE_HPP
#define BREAKOUT_STATE_HPP

namespace machine
{
/**
 * @brief All possible state types.
 */
enum class StateType
{
    INTRO,
    MENU,
    GAME,
    END,
    SCOREBOARD,

};

/**
 * @brief State interface.
 *
 * Represents state of game / application.
 * All states shall implement this interface.
 */
class State
{
public:
    State()          = default;
    virtual ~State() = default;

    State(const State&) = delete;
    State& operator=(const State&) = delete;

    /**
     * @brief Updates the game scene / application.
     * @param deltaTime value used for slowing down frames.
     */
    virtual void update(const float deltaTime) = 0;

    /**
     * @brief Handles the input captured from keyboard and mouse etc..
     */
    virtual void handleInput()                 = 0;

    /**
     * @brief Draws the scene to screen.
     *
     * @note Screen implementation shall be encapsulated from user.
     */
    virtual void draw()                        = 0;

    /**
     * @brief Resumes paused state.
     *
     * @note This method shall be called only if pause was called before.
     */
    virtual void resume(){};

    /**
     * @note Pauses current state.
     *
     * @note This method shall be called only if state is running.
     */
    virtual void pause(){};
};
}  // namespace machine

#endif  // BREAKOUT_STATE_HPP
