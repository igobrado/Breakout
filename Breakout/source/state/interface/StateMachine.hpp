#ifndef BREAKOUT_STATEMACHINE_HPP
#define BREAKOUT_STATEMACHINE_HPP

#include "State.hpp"
#include <memory>
#include <stack>

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
     * @brief Removes state from the top of the state stack.
     */
    void removeState();

    /**
     * @brief Processes data that was input true the addState / removeState API's.
     *
     * If there is not states on stack that are running or supposed to run.
     * Game / application will terminate.
     *
     */
    void processChanges();

    /**
     * @return Reference to a current running state. If returned value is being ignored, compiler will raise a warning.
     */
    [[nodiscard]] const std::unique_ptr<State>& activeState() const;
private:
    bool mIsReplacing;
    bool mIsAdding;
    bool mIsRemoving;
    bool mShouldStop;

    std::stack<std::unique_ptr<State>> mStates;
    std::unique_ptr<State>             mNextState;
};

}  // namespace machine

#endif  // BREAKOUT_STATEMACHINE_HPP
