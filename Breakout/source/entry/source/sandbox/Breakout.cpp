#include "Breakout.hpp"

namespace game
{

Breakout::Breakout(const ScreenDimensions dimensions, const char* applicationName)
    : mGameData(std::make_shared<::common::GameData>(dimensions, applicationName))
    , mTestShape{ 100.0f }
{
}

int Breakout::run()
{
    // TODO: Initialization
    mTestShape.setFillColor(sf::Color::Green);

    return loop();
}

int Breakout::loop()
{
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