#ifndef BREAKOUT_STATEMACHINE_HPP
#define BREAKOUT_STATEMACHINE_HPP

#include "State.hpp"
#include <memory>
#include <stack>

namespace machine
{
class StateMachine
{
public:
    StateMachine();
    void addState(std::unique_ptr<State> newState, bool isReplacing = true);
    void removeState();
    void processChanges();

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
