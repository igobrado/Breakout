#include "Breakout.hpp"

#include "StateFactory.hpp"

namespace game
{

Breakout::Breakout(const char* applicationName)
    : mGameData{ std::make_shared<::common::GameData>(applicationName) }
    , mClock{}
{
    mGameData->machine().addState(StateFactory::getState(machine::StateType::INTRO, *mGameData));
}

int Breakout::run()
{
    float newTime, frameTime;
    float currentTime         = mClock.getElapsedTime().asSeconds();
    float accumulator         = 0.0f;

    while (mGameData->window().isOpen())
    {
        mGameData->machine().processChanges();
        newTime   = mClock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;
        if (frameTime > 0.25f)
        {
            frameTime = 0.025f;
        }
        currentTime = newTime;
        accumulator += frameTime;
        while (accumulator > sDeltaTime)
        {
            const auto& activeState = mGameData->machine().activeState();
            activeState->handleInput();
            activeState->update(sDeltaTime);
            if (mGameData->machine().shouldStopApplication())
            {
                mGameData->window().close();
            }
            accumulator -= sDeltaTime;
        }

        mGameData->machine().activeState()->draw();
    }
    return 0;
}

}  // namespace game