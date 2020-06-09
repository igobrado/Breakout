#ifndef BREAKOUT_CONFIG_HPP
#define BREAKOUT_CONFIG_HPP
#include <SFML/Graphics.hpp>

/**
 * @brief Used only for more logical structure.
 *
 * @note Every config class shall inherit from it.
 */
class Config
{
public:
    virtual ~Config() = default;

    /**
     * @brief Draws all widgets to the screen (if there are any).
     *
     * @param window
     */
    virtual void drawAllComponents(sf::RenderWindow& window) = 0;
};

#endif  // BREAKOUT_CONFIG_HPP