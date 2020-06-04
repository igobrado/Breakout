#ifndef BREAKOUT_MOVEABLE_HPP
#define BREAKOUT_MOVEABLE_HPP

#include <SFML/Graphics.hpp>

enum class Direction
{
    Left,
    Right,

    _NoHandle
};

class Moveable
{
public:
    Moveable()          = default;
    virtual ~Moveable() = default;

    Moveable(const Moveable&) = delete;
    Moveable& operator=(const Moveable&) = delete;

    virtual void                updateMovement(const float& deltaTime) = 0;
    virtual const sf::Vector2f& position()                             = 0;
    virtual sf::FloatRect       globalBounds()                         = 0;
};

#endif  // BREAKOUT_MOVEABLE_HPP
