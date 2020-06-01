#ifndef BREAKOUT_APPLICATION_HPP
#define BREAKOUT_APPLICATION_HPP

#include <iostream>
#include <cstdint>

class Application
{
public:
    Application() = default;
    virtual ~Application() = default;
    virtual int run() = 0;

protected:
    virtual void loop() = 0;
};

#endif //BREAKOUT_APPLICATION_HPP
