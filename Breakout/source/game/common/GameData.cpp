#include "GameData.hpp"

namespace common
{
GameData::GameData(const ScreenDimensions dimensions, const char* applicationName)  //
    : mScreenDimensions{ dimensions }
    , mWindow{ sf::VideoMode{ mScreenDimensions.width, mScreenDimensions.height }, applicationName }  //
    {};

sf::RenderWindow& GameData::window()
{
    return mWindow;
}

}  // namespace common