#ifndef BREAKOUT_DRAWABLE_HPP
#define BREAKOUT_DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class Drawable
{
public:
    Drawable()          = default;
    virtual ~Drawable() = default;

    Drawable(const Drawable&) = delete;
    Drawable& operator=(const Drawable&) = delete;

    virtual void Draw(sf::RenderWindow& window) = 0;
};

#endif  // BREAKOUT_DRAWABLE_HPP
