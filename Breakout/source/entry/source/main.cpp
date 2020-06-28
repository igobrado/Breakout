#include "app/Breakout.hpp"

#include <fstream>

#ifndef _WINDOWS
int main()
#else  //
#include <Windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
#endif
{
    int rv = 0;

    try
    {
	    std::unique_ptr<Application> breakout = std::make_unique<game::Breakout>(  //
		    "Breakout");
        rv = breakout->run();
    }
    catch (const std::out_of_range& except) ///< Instance of breakout might throw since it has resource holder which depends on file paths
    {
        std::ofstream errorLog{ "ErrorLog.txt", std::ios::out };
        std::stringstream ss;
        ss << except.what() << "Check configuration files where did you put them?" << std::endl;
        errorLog << ss.str() << std::endl;
        rv = -1;
#ifdef _WINDOWS
        MessageBox(nullptr, ss.str().c_str() , "Configuration file error", MB_OK);
#endif  // _WINDOWS


    }
    return rv;
}  //
