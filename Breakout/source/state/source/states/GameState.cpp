#include "GameState.hpp"

namespace machine
{

GameState::GameState(common::GameData& gameData)  //
    : State{}
    , mGameData{ gameData }
    , mLevelStack{}
    , mBackground{ mGameData.resource().getTexture("low") }
{
    gui::BrickDef    red{ 1, gui::BrickColor::RED };
    gui::BrickDef    blue{ 1, gui::BrickColor::BLUE };
    gui::BrickDef    green{ 1, gui::BrickColor::GREEN };
    gui::BrickDef    cyan{ 1, gui::BrickColor::CYAN };
    BrickDefinitions tst{ red, blue, green, cyan };

    mLevelStack.push(Level{ mGameData.resource(), tst, []() {} });

}

void GameState::update(const float deltaTime)
{
    mLevelStack.update(deltaTime);
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
    mGameData.window().clear();
    mGameData.window().draw(mBackground);
    mLevelStack.draw(mGameData.window());
    mGameData.window().display();
}

void GameState::onMouseKeyPressed(const sf::Mouse::Button button)
{
}

}  // namespace machine