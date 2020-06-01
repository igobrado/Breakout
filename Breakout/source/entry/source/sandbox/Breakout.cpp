#include "Breakout.hpp"

namespace game
{

Breakout::Breakout(const ScreenDimensions dimensions, const char* applicationName)
    : mGameData(std::make_shared<::common::GameData>(dimensions, applicationName))
    , mTestShape{ 100.0f }
    , mClock{}
{
}

int Breakout::run()
{
    // TODO: Initialization
    //float newTime, frameTime;
    //float currentTime = mClock.getElapsedTime().asSeconds();
    //float accumulator = 0.0f;

    //while (mGameData->window().isOpen())
    //{
    //    mGameData->machine().processChanges();
    //    newTime   = mClock.getElapsedTime().asSeconds();
    //    frameTime = newTime - currentTime;
    //    if (frameTime > 0.25f)
    //    {
    //        frameTime = 0.025f;
    //    }
    //    currentTime = newTime;
    //    accumulator += frameTime;
    //    //loop(accumulator);
    //    // TODO: Extern loop
    //    mGameData->machine().activeState()->draw();
    //}
    //return 0;
    mTestShape.setFillColor(sf::Color::Green);

    return loop(0);
}

int Breakout::loop(float accumulator)
{
    //while (accumulator > sDeltaTime)
    //{
    //    const auto& activeState = mGameData->machine().activeState();
    //    activeState->handleInput();
    //    activeState->update(sDeltaTime);
    //    accumulator -= sDeltaTime;
    //}
    sf::RenderWindow& window = mGameData->window();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }
        window.clear();
        window.draw(mTestShape);
        window.display();
    }
    return -1;
}

}  // namespace game