#include "GameData.hpp"

namespace common
{
GameData::GameData(const char* applicationName)  //
    : mScreenDimensions{ ::sScreenDimensions }
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

ResourceHolder& GameData::resource()
{
    return mResourceHolder;
}

}  // namespace common