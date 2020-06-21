#ifndef BREAKOUT_STATEMACHINE_HPP
#define BREAKOUT_STATEMACHINE_HPP

#include <memory>
#include <stack>

#include "State.hpp"

namespace machine
{

/**
 * @note Represents core functionality of application / game.
 *
 * In this class main game loop and logic of state handing implemented.
 */
class StateMachine
{
public:
    StateMachine();
    /**
     * @brief Adds state to top of stack.
     *
     * New state shall begin when processChanges is called next time.
     *
     * @param newState Next state.
     * @param isReplacing Shall current running state be replaced by new.
     */
    void addState(std::unique_ptr<State> newState, bool isReplacing = true);

    /**
     * @brief Processes data that was input true the addState / removeState API's.
     *
     * If there is not states on stack that are running or supposed to run.
     * Game / application will terminate.
     */
    void processChanges();

    /**
     * @return Reference to a current running state. If returned value is being ignored, compiler will raise a warning.
     */
    [[nodiscard]] const std::unique_ptr<State>& activeState() const;

    /**
     * @brief Stops the application.
     */
    void stopApplication();

    /**
     * @return true if application should stop, otherwise false.
     */
    [[nodiscard]] bool shouldStopApplication() const;

private:
    bool mIsReplacing;  ///< Indicates is replacing between screens being done.
    bool mIsAdding;     ///< Indicates that is adding new state being done.
    bool mIsRemoving;   ///< Indicates should old state be removed from state stack.
    bool mShouldStop;   ///< Indicates should game stop running.

    std::stack<std::unique_ptr<State>> mStates;     ///< Stack of the states currently in progress.
    std::unique_ptr<State>             mNextState;  ///< Waiting state.
};

}  // namespace machine

#endif  // BREAKOUT_STATEMACHINE_HPP
