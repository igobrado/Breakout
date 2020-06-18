#include "InputState.hpp"

#include "StateConfigs/InputStateConfig.hpp"
namespace machine
{

InputState::InputState(common::GameData& gameData)  //
    : State{}
    , mGameData{ gameData }
    , mBackground{ gameData.resource().getTexture("low") }
    , mConfig{ gameData.resource().getConfig("input") }
{
}

void InputState::update(const float deltaTime)
{
    mConfig.updateMovableComponents(deltaTime);
}

void InputState::handleInput()
{
    sf::Event         eventToProcess{};
    sf::RenderWindow& window = mGameData.window();
    while (window.pollEvent(eventToProcess))
    {
        if (eventToProcess.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            window.close();
        }
        else if (eventToProcess.type == sf::Event::TextEntered)
        {
            dynamic_cast<InputStateConfig&>(mConfig).handleInput(eventToProcess);
        }
    }
}

void InputState::draw()
{
    mGameData.window().clear();
    mGameData.window().draw(mBackground);
    mConfig.drawAllComponents(mGameData.window());
    mGameData.window().display();
}

}  // namespace machine