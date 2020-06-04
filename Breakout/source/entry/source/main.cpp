#include "sandbox/Breakout.hpp"
///#include "State.hpp"
int main()
{
    std::unique_ptr<Application> breakout = std::make_unique<game::Breakout>(
            ScreenDimensions{ 800, 600  },
            "Breakout");
    return breakout->run();
}