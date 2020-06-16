#include "GameData.hpp"

#include "StateFactory.hpp"

namespace common
{
GameData::GameData(const char* applicationName)  //
    : mIntroStateSwitchesCallbackMap{ { "Enter name", [this]() { switchState(::machine::StateType::INPUT); } },
                                      { "Scoreboard", [this]() { switchState(::machine::StateType::SCOREBOARD); } },
                                      { "Quit game", [this]() { mStateMachine.stopApplication(); } } }
    , mInputStateSwitchesCallback{ [this](const Player& player) {
        mScoreboard.newPlayer(player);
        switchState(::machine::StateType::GAME);
    } }
    , mScreenDimensions{ ::sScreenDimensions }
    , mWindow{ sf::VideoMode(mScreenDimensions.width, mScreenDimensions.height), applicationName }
    , mStateMachine{}
    , mResourceHolder{ mWindow, mIntroStateSwitchesCallbackMap, mInputStateSwitchesCallback }
    , mScalingFactorX{ static_cast<float>(mWindow.getSize().x / 1280.) }
    , mScalingFactorY{ static_cast<float>(mWindow.getSize().y / 720.) }
    , mScoreboard{ "Scoreboard.txt", mResourceHolder.getFont("asrfont") }
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

Scoreboard& GameData::scoreboard()
{
    return mScoreboard;
}

}  // namespace common