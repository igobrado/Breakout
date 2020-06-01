#ifndef BREAKOUT_MENUSTATE_HPP
#define BREAKOUT_MENUSTATE_HPP

#include "State.hpp"

namespace machine
{

class MenuState : public State
{
public:
    void update(const float deltaTime) override;
    void handleInput()                 override;
    void draw()                        override;
};

}

#endif  // BREAKOUT_MENUSTATE_HPP
