#include "sandbox/Breakout.hpp"

int main()
{
    std::unique_ptr<Application> breakout = std::make_unique<game::Breakout>(
            ScreenDimensions{ 1920, 1080 },
            "Breakout");
    return breakout->run();
}