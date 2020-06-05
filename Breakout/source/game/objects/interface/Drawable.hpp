#ifndef BREAKOUT_DRAWABLE_HPP
#define BREAKOUT_DRAWABLE_HPP

#include <SFML/Graphics.hpp>

/**
 * @brief Interface for objects that can be drawn to the screen.
 *
 * @note Only objects that can be
 * drawn to screen shall implement this interface.
 */
class Drawable
{
public:
    Drawable()          = default;
    virtual ~Drawable() = default;

    Drawable(const Drawable&) = delete;
    Drawable& operator=(const Drawable&) = delete;

    /**
     * @brief calls API from render window RenderWindow::draw() and draws object to screen.
     *
     * @note Valid reference shall be provided.
     *
     * @param window target screen where object shall be drawn.
     */
    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif  // BREAKOUT_DRAWABLE_HPP
