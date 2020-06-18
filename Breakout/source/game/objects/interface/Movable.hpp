#ifndef BREAKOUT_MOVABLE_HPP
#define BREAKOUT_MOVABLE_HPP

#include <SFML/Graphics.hpp>

enum class Direction
{
    Left,
    Right,

    _NoHandle
};

/**
 * @note Intended to be empty.
 * Used to avoid multiple getters like getPosition(), getGlobalBounds() etc..
 * All definition types classes shall inherit from it
 * and return relevant data from virtual method \see Movable::mLevelBrickDefinitions
 */
struct Definitions
{
    Definitions(sf::Vector2f currentPosition, sf::FloatRect globalBounds, sf::Vector2f scalingFactor)
        : currentPosition(currentPosition)
        , globalBounds{ globalBounds }
        , scalingFactor{ scalingFactor }
    {
    }

    sf::Vector2f  currentPosition;
    sf::FloatRect globalBounds;
    sf::Vector2f  scalingFactor;
};

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
     * @brief Returns definition data for specific object.
     *
     * @note If returning upcasted version I.E.
     * BrickDefinitions -> Definitions, Casting **should** be safe.
     * But be aware of that it can throw.
     *
     * @return  Reference to Definition class.
     */
    virtual const Definitions& definitions() = 0;

    /**
     * @brief Updates objects current position to next calculated.
     *
     * @param deltaTime slows object moving by delta time.
     */
    virtual void updateMovement(const float& deltaTime) = 0;
};

#endif  // BREAKOUT_MOVABLE_HPP
