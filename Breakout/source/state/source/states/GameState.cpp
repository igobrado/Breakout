#include "GameState.hpp"

namespace machine
{

GameState::GameState(common::GameData& gameData)  //
    : State{}
    , mGameData{ gameData }
{
}
GameState::~GameState()
{
    // cleanup
}

void GameState::update(const float deltaTime)
{
}

void GameState::handleInput()
{
    sf::Event         eventToProcess{};
    sf::RenderWindow& window = mGameData.window();
    while (window.pollEvent(eventToProcess))
    {
        if (eventToProcess.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void GameState::draw()
{
}

void GameState::onMouseKeyPressed(const sf::Mouse::Button button)
{
}

}  // namespace machine