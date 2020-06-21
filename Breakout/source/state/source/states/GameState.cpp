#include "GameState.hpp"

#include <random>

namespace machine
{

GameState::GameState(common::GameData& gameData)  //
    : State{}
    , mGameData{ gameData }
    , mLevelStack{}
    , mBackground{ mGameData.resource().getTexture("low") }
    , mShouldContinue{ true }
    , mLevelBrickDefinitions{}
    , mNumberOfLevels{ 2U }
{

    // TODO: Configuration file
    gui::BrickDef red{ 1, gui::BrickColor::RED };
    gui::BrickDef blue{ 1, gui::BrickColor::BLUE };
    gui::BrickDef green{ 1, gui::BrickColor::GREEN };
    gui::BrickDef cyan{ 1, gui::BrickColor::CYAN };

    gui::BrickDef redTwo{ 3, gui::BrickColor::RED };
    gui::BrickDef blueTwo{ 2, gui::BrickColor::BLUE };
    gui::BrickDef greenTwo{ 4, gui::BrickColor::GREEN };
    gui::BrickDef cyanTwo{ 1, gui::BrickColor::CYAN };

    mLevelBrickDefinitions.push_back(BrickDefinitions{ red, blue, green, cyan });
    mLevelBrickDefinitions.push_back(BrickDefinitions{ redTwo, blueTwo, greenTwo, cyanTwo });

    mLevelStack.push(
            Level{ mGameData.resource(),
                   *(mLevelBrickDefinitions.begin()),
                   [this]() { mGameData.switchState(StateType::END); },
                   [this](int increaseNumber) { mGameData.scoreboard().increaseCurrentPlayerScore(increaseNumber); },
                   mGameData.scalingFactor() });
    --mNumberOfLevels;
}

void GameState::update(const float deltaTime)
{
    if (mShouldContinue)
    {
        if (mLevelStack.update(deltaTime))
        {
            if (mNumberOfLevels)
            {
                mShouldContinue = false;
                mLevelStack.top().createLevelFromBegining(mLevelBrickDefinitions[mNumberOfLevels]);
                --mNumberOfLevels;
            }
            else
            {
                mGameData.switchState(::machine::StateType::END);
            }
        }
    }
}

void GameState::handleInput()
{
    sf::Event         eventToProcess{};
    sf::RenderWindow& window = mGameData.window();
    while (window.pollEvent(eventToProcess))
    {
        if (eventToProcess.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
            mShouldContinue = true;
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