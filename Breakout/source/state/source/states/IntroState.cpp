#include "IntroState.hpp"

#include <Level.hpp>

#include "StateFactory.hpp"

namespace machine
{

IntroState::IntroState(common::GameData& gameData)  //
    : State{}
    , mGameData{ gameData }
    , mBackground{ mGameData.resource().getTexture("statetwo") }
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
        if (eventToProcess.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
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

}  // namespace machine