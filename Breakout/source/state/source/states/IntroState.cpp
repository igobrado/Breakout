#include "IntroState.hpp"

#include <Level.hpp>

#include "StateFactory.hpp"

namespace machine
{

IntroState::IntroState(common::GameData& gameData)  //
    : State{}
    , mGameData{ gameData }
    , mBackground{ mGameData.resource().getTexture("statetwo") }
    , mSwapTime{ 6.0f }
    , mClock{}
    , mStateConfig{ gameData.resource().getConfig("intro") }
{
}

void IntroState::update(const float deltaTime)
{
    mStateConfig.updateMovableComponents(deltaTime);
}

void IntroState::handleInput()
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

void IntroState::draw()
{
    mGameData.window().clear();
    mGameData.window().draw(mBackground);
    mStateConfig.drawAllComponents(mGameData.window());
    mGameData.window().display();
}

void IntroState::onMouseKeyPressed(const sf::Mouse::Button button)
{
}

}  // namespace machine