#include "IntroState.hpp"

namespace machine
{

IntroState::IntroState(common::GameData& gameData)  //
    : State{}
    , mGameData{ gameData }
{
}
IntroState::~IntroState()
{
    // cleanup
}

void IntroState::update(const float deltaTime)
{
}

void IntroState::handleInput()
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

void IntroState::draw()
{
}

void IntroState::onMouseKeyPressed(const sf::Mouse::Button button)
{
}

}  // namespace machine