#include "sandbox/Breakout.hpp"

#ifdef DEBUG
#include <fstream>
static long allocations = 0;

void* operator new(size_t size)
{
    ++allocations;

    void * p = malloc(size);
    return p;
}
void operator delete(void* p)
{
    --allocations;
	free(p);
}
#endif

#ifndef _WINDOWS
int main()
#else  //
#include <Windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
#endif
{
    int rv = 0;

    {///< only to track are all objects clean up after game finishes
     ///< TODO: DELETE BEFORE RELEASE
	    std::unique_ptr<Application> breakout = std::make_unique<game::Breakout>(  //
		    "Breakout");
        rv = breakout->run();
    }

#ifdef DEBUG
    std::ofstream file("Allocations.txt");
    file << allocations;
#endif
    return rv;
}  //
