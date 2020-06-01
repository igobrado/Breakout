#include "MenuState.hpp"

namespace machine
{

MenuState::MenuState(common::GameData& gameData)  //
        : State{}
        , mGameData{ gameData }
{
}
MenuState::~MenuState()
{
    // cleanup
}

void MenuState::update(const float deltaTime)
{
}

void MenuState::handleInput()
{
    sf::Event eventToProcess{};
    sf::RenderWindow& window = mGameData.window();
    while (window.pollEvent(eventToProcess))
    {
        if (eventToProcess.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void MenuState::draw()
{
}

void MenuState::onMouseKeyPressed(const sf::Mouse::Button button)
{
}

}  // namespace machine