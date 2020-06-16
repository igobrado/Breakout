#include "ScoreboardState.hpp"

namespace machine
{

ScoreboardState::ScoreboardState(common::GameData& gameData)  //
        : State{}
        , mGameData{ gameData }
        , mBackground{ mGameData.resource().getTexture("statetwo") }
{
    mGameData.scoreboard().write();
}

void ScoreboardState::update(const float deltaTime)
{
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Backspace))
    {
        mGameData.switchState(::machine::StateType::INTRO);
    }
}

void ScoreboardState::handleInput()
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

void ScoreboardState::draw()
{
    mGameData.window().clear();
    mGameData.window().draw(mBackground);
    mGameData.scoreboard().draw(mGameData.window());
    mGameData.window().display();
}

}  // namespace machine