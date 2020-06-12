#include "EndState.hpp"

namespace machine
{

EndState::EndState(common::GameData& gameData)  //
    : State{}
    , mGameData{ gameData }
    , mBackground{ mGameData.resource().getTexture("statetwo") }

{
}

void EndState::update(const float deltaTime)
{
}

void EndState::handleInput()
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

void EndState::draw()
{
    mGameData.window().clear();
    mGameData.window().draw(mBackground);
    mGameData.window().display();
}

void EndState::onMouseKeyPressed(const sf::Mouse::Button button)
{
}

}  // namespace machine