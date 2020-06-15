#include "EndState.hpp"

namespace machine
{

EndState::EndState(common::GameData& gameData)  //
    : State{}
    , mGameData{ gameData }
    , mBackground{ mGameData.resource().getTexture("statetwo") }

{
    mGameData.scoreboard().sort();
}

void EndState::update(const float deltaTime)
{
    /**
     * TODO: implement update method, updating the cursor etc..
     */
}

void EndState::handleInput()
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

void EndState::draw()
{
    mGameData.window().clear();
    mGameData.window().draw(mBackground);
    mGameData.scoreboard().draw(mGameData.window());
    mGameData.window().display();
}

}  // namespace machine