#ifndef BREAKOUT_MOVABLE_HPP
#define BREAKOUT_MOVABLE_HPP

#include <SFML/Graphics.hpp>

/**
 * @brief Interface for game objects that can be moved around the screen.
 *
 * @note Only object that can be moved around the screen
 * shall inherit from this class.
 */
class Movable
{
public:
    Movable()          = default;
    virtual ~Movable() = default;

    /**@brief deleted copy constructor*/
    Movable(const Movable&) = delete;

    /**@brief deleted copy assign operator*/
    Movable& operator=(const Movable&) = delete;

    /**
     * @brief Updates objects current position to next calculated.
     *
     * @param deltaTime slows object moving by delta time.
     */
    virtual void updateMovement(const float& deltaTime) = 0;
};

#endif  // BREAKOUT_MOVABLE_HPP
