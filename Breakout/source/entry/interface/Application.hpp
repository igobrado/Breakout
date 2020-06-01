#ifndef BREAKOUT_APPLICATION_HPP
#define BREAKOUT_APPLICATION_HPP

#include <cstdint>
#include <iostream>

class Application
{
  public:
    Application()          = default;
    virtual ~Application() = default;
    virtual int run()      = 0;

  protected:
    virtual int loop() = 0;
};

#endif //BREAKOUT_APPLICATION_HPP
