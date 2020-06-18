#include "EndState.hpp"

namespace machine
{

EndState::EndState(common::GameData& gameData)  //
    : State{}
    , mGameData{ gameData }
    , mBackground{ mGameData.resource().getTexture("statetwo") }

{
    mGameData.scoreboard().write();
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
        if (eventToProcess.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            mGameData.switchState(::machine::StateType::GAME);
        }
    }
}

void EndState::draw()
{
    mGameData.window().clear();
    mGameData.window().draw(mBackground);
    mGameData.scoreboard().draw(mGameData.window());
    mGameData.window().display();
}

}  // namespace machine