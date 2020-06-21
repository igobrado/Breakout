#include "StateMachine.hpp"

namespace machine
{

StateMachine::StateMachine()
    : mIsReplacing{ true }
    , mIsAdding{ true }
    , mIsRemoving{ false }
    , mShouldStop{ false }
    , mStates{}
    , mNextState{ nullptr }
{
}

void StateMachine::addState(std::unique_ptr<State> newState, bool isReplacing)
{
    if (newState)
    {
        mNextState   = std::move(newState);
        mIsAdding    = true;
        mIsReplacing = isReplacing;
    }
}

void StateMachine::processChanges()
{
    if (mIsRemoving && !mStates.empty())
    {
        mStates.pop();
        mIsRemoving = false;
    }
    if (mIsAdding)
    {
        if (!mStates.empty())
        {
            if (mIsReplacing)
            {
                mStates.pop();
            }
        }

        mStates.push(std::move(mNextState));
        mIsAdding = false;
    }
}

const std::unique_ptr<State>& StateMachine::activeState() const
{
    return mStates.top();
}

void StateMachine::stopApplication()
{
    mShouldStop = true;
}

bool StateMachine::shouldStopApplication() const
{
    return mShouldStop;
}

}  // namespace machine