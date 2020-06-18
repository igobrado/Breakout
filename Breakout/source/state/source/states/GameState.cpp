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
    std::random_device                     rd;
    std::mt19937                           mt(rd());
    std::uniform_int_distribution<uint8_t> dist(1, 3);

    for (uint8_t i = 1; i != mNumberOfLevels; ++i)
    {
        gui::BrickDef red{ dist(mt), gui::BrickColor::RED, mGameData.scalingFactor() };
        gui::BrickDef blue{ dist(mt), gui::BrickColor::BLUE, mGameData.scalingFactor() };
        gui::BrickDef green{ dist(mt), gui::BrickColor::GREEN, mGameData.scalingFactor() };
        gui::BrickDef cyan{ dist(mt), gui::BrickColor::CYAN, mGameData.scalingFactor() };
        mLevelBrickDefinitions.push_back(BrickDefinitions{ red, blue, green, cyan });
    }

    mLevelStack.push(Level{
            mGameData.resource(),
            *(mLevelBrickDefinitions.begin()),
            [this]() { mGameData.switchState(StateType::END); },
            [this](int increaseNumber) { mGameData.scoreboard().increaseCurrentPlayerScore(increaseNumber); } });
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
        if (eventToProcess.type == sf::Event::Closed)
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