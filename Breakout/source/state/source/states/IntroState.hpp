#ifndef BREAKOUT_INTROSTATE_HPP
#define BREAKOUT_INTROSTATE_HPP

#include "State.hpp"

namespace machine
{

class IntroState : public State
{
public:
    void update(const float deltaTime) override;
    void handleInput()                 override;
    void draw()                        override;
};

}
#endif  // BREAKOUT_INTROSTATE_HPP
