#ifndef BREAKOUT_LEVELSTACK_HPP
#define BREAKOUT_LEVELSTACK_HPP

#include <stack>

#include "Level.hpp"

class LevelStack : public std::stack<Level>
{
public:
    void draw(sf::RenderWindow& window)
    {
        c.begin()->draw(window);
    }

    bool update(const float& deltaTime)
    {
        return c.begin()->update(deltaTime);
    }

};
#endif  // BREAKOUT_LEVELSTACK_HPP
