#include "GameData.hpp"

namespace common
{
GameData::GameData(ScreenDimensions dimensions, const char* applicationName)  //
    : mScreenDimensions{ dimensions }
    , mWindow{ sf::VideoMode{ mScreenDimensions.width, mScreenDimensions.height }, applicationName }
    , mStateMachine{}
    , mResourceHolder{}
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

}  // namespace common