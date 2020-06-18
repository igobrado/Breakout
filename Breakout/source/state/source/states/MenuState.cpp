#include "MenuState.hpp"

namespace machine
{

MenuState::MenuState(common::GameData& gameData)  //
        : State{}
        , mGameData{ gameData }
        , mBackground{ mGameData.resource().getTexture("statetwo") }
{
}

void MenuState::update(const float deltaTime)
{
}

void MenuState::handleInput()
{
    sf::Event eventToProcess{};
    sf::RenderWindow& window = mGameData.window();
    if (eventToProcess.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        if (eventToProcess.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void MenuState::draw()
{
    mGameData.window().clear();
    mGameData.window().draw(mBackground);
    mGameData.window().display();
}

}  // namespace machine