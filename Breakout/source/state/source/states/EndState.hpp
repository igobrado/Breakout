#ifndef BREAKOUT_ENDSTATE_HPP
#define BREAKOUT_ENDSTATE_HPP

#include "State.hpp"

namespace machine
{

class EndState : public State
{
public:
    void update(const float deltaTime) override;
    void handleInput()                 override;
    void draw()                        override;
};

}  // namespace machine

#endif  // BREAKOUT_ENDSTATE_HPP
