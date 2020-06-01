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
        mNextState = std::move(newState);
        mIsAdding = true;
        mIsReplacing = isReplacing;
    }
}

void StateMachine::removeState()
{
    mIsRemoving = false;
}

void StateMachine::processChanges()
{
    if (!mShouldStop)
    {
        if (mIsRemoving && !mStates.empty())
        {
            mStates.pop();

            if (!mStates.empty())
            {
                mStates.top()->resume();
            }

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
                else
                {
                    mStates.top()->pause();
                }
            }

            mStates.push(std::move(mNextState));
            mIsAdding = false;
        }
    }
}

const std::unique_ptr<State>& StateMachine::activeState() const
{
    return mStates.top();
}

}  // namespace machine