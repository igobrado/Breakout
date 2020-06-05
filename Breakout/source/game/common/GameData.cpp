#include "GameData.hpp"

namespace common
{
GameData::GameData(const char* applicationName)  //
    : mScreenDimensions{ ::sScreenDimensions }
    , mWindow{ sf::VideoMode(mScreenDimensions.width, mScreenDimensions.height), applicationName }
    , mStateMachine{}
    , mResourceHolder{}
    , mScalingFactorX{ static_cast<float>(mWindow.getSize().x / 1280.) }
    , mScalingFactorY{ static_cast<float>(mWindow.getSize().y / 720.) }
{
}

sf::RenderWindow& GameData::window()
{
    return mWindow;
}

::machine::StateMachine& GameData::machine()
{
    return mStateMachine;
}

void GameData::switchState(::machine::StateType /*stateType*/, GameData& /*gameData*/)
{
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