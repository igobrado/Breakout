#include "GameData.hpp"

#include "StateFactory.hpp"

namespace common
{
GameData::GameData(const char* applicationName)  //
    : mIntroStateSwitchesCallbackMap{ { "New game", [this]() { switchState(::machine::StateType::GAME); } },
                                      { "Enter name", [this]() { switchState(::machine::StateType::GAME); } },
                                      { "Quit game", [this]() { switchState(::machine::StateType::GAME); } },
                                      { "Scoreboard", [this]() { switchState(::machine::StateType::SCOREBOARD); } } }
    , mScreenDimensions{ ::sScreenDimensions }
    , mWindow{ sf::VideoMode(mScreenDimensions.width, mScreenDimensions.height), applicationName }
    , mStateMachine{}
    , mResourceHolder{ mWindow, mIntroStateSwitchesCallbackMap }
    , mScalingFactorX{ static_cast<float>(mWindow.getSize().x / 1280.) }
    , mScalingFactorY{ static_cast<float>(mWindow.getSize().y / 720.) }
{
    mWindow.setMouseCursorVisible(false);
}

sf::RenderWindow& GameData::window()
{
    return mWindow;
}

::machine::StateMachine& GameData::machine()
{
    return mStateMachine;
}

void GameData::switchState(::machine::StateType stateType)
{
    mStateMachine.addState(StateFactory::getState(stateType, *this));
}

ResourceHolder& GameData::resource()
{
    return mResourceHolder;
}

sf::Vector2f GameData::scalingFactor() const
{
    return sf::Vector2f{ mScalingFactorX, mScalingFactorY };
}

}  // namespace common