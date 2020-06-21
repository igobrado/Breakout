#ifndef BREAKOUT_LEVELSTACK_HPP
#define BREAKOUT_LEVELSTACK_HPP

#include <stack>

#include "Level.hpp"

class LevelStack : public std::stack<Level>
{
public:
    /**
     * @brief Draws level content to the screen
     *
     * @param window
     */
    void draw(sf::RenderWindow& window)
    {
        c.begin()->draw(window);
    }

    /**
     * @brief Updates the levels scene.
     *
     * @param deltaTime
     * @return true if level should end, false if not.
     */
    bool update(const float& deltaTime)
    {
        return c.begin()->update(deltaTime);
    }
};
#endif  // BREAKOUT_LEVELSTACK_HPP
