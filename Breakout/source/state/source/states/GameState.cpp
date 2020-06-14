#include "GameState.hpp"

namespace machine
{

GameState::GameState(common::GameData& gameData)  //
    : State{}
    , mGameData{ gameData }
    , mLevelStack{}
    , mBackground{ mGameData.resource().getTexture("low") }
{
    gui::BrickDef    red{ 1, gui::BrickColor::RED, mGameData.scalingFactor() };
    gui::BrickDef    blue{ 1, gui::BrickColor::BLUE, mGameData.scalingFactor() };
    gui::BrickDef    green{ 1, gui::BrickColor::GREEN, mGameData.scalingFactor() };
    gui::BrickDef    cyan{ 1, gui::BrickColor::CYAN, mGameData.scalingFactor() };
    BrickDefinitions levelDefinitions{ red, blue, green, cyan };

    mLevelStack.push(Level{
            mGameData.resource(),
            levelDefinitions,
            [this]() { mGameData.switchState(StateType::END); },
            [this](int increaseNumber) { mGameData.scoreboard().increaseCurrentPlayerScore(increaseNumber); } });
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

}  // namespace machine