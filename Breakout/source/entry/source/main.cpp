#include "sandbox/Breakout.hpp"

#ifndef WIN_32
int main()
#else  //
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
#endif
{
    std::unique_ptr<Application> breakout = std::make_unique<game::Breakout>(  //
            "Breakout");
    return breakout->run();
}  //
