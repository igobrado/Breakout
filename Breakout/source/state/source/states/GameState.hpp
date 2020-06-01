//
// Created by iob on 01. 06. 2020..
//

#ifndef BREAKOUT_GAMESTATE_HPP
#define BREAKOUT_GAMESTATE_HPP

#include "State.hpp"

namespace machine
{

class GameState : public State
{
public:
    void update(const float deltaTime) override;
    void handleInput()                 override;
    void draw()                        override;
};

}
#endif  // BREAKOUT_GAMESTATE_HPP
