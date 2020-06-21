#ifndef BREAKOUT_BRICK_HPP
#define BREAKOUT_BRICK_HPP

#include <SFML/Graphics.hpp>

namespace gui
{

/**
 * @brief Brick color that are suppored.
 */
enum class BrickColor
{
    RED   = 0,
    BLUE  = 1,
    GREEN = 2,
    CYAN  = 3
};

/**
 * @brief Converts brick color to the string.
 *
 * @param color
 * @return stringified color name. If color is invalid then "invalid" is returned.
 */
static constexpr const char* toString(BrickColor color)
{
    switch (color)
    {
        case BrickColor::RED:
            return "red";
        case BrickColor::BLUE:
            return "blue";
        case BrickColor::GREEN:
            return "green";
        case BrickColor::CYAN:
            return "cyan";
        default:
            return "invalid";
    }
}

/**
 * @brief Holds ball important data.
 */
struct BrickDef
{
    BrickDef(std::uint16_t brickStrength, BrickColor color)  //
        : brickStrength(brickStrength)
        , color(color)
        , currentPosition{ 0.0f, 0.0f }
    {
    }

    std::uint16_t brickStrength;    ///< Strength of the brick. Brick on every hit loses one point.
    BrickColor    color;            ///< Color of the brick.
    sf::Vector2f  currentPosition;  ///< Where is brick located.
};

/**
 * @brief Represents Ball object, wraps sf::Sprite class to abstract brick.
 *
 * @note implements interfaces: \see Movable \see Drawable
 */
class Brick : public sf::Sprite
{
public:
    Brick(const sf::Texture& texture, BrickDef definition);
    /**
     * @brief Checks whether brick strength came down to 0.
     *
     * @note If Brick strength comes to 0, brick shall destroy.
     *
     * @return true if brick strength is 0 false if not.
     */
    bool shouldDestroy() const;

    /**
     * @brief Checks whether brick is collided with given rect and handles onHit event.
     *
     * @param rect
     * @return true if yes, false if not.
     */
    bool isCollided(sf::FloatRect rect);

    /**
     * @brief Calculates globalBounds on more proper way provided from SFML library.
     *
     * @return
     */
    sf::FloatRect handlyCalculatedGlobalBounds() const;

protected:
    /**
     * @brief Decreases bricks life by one.
     *
     * @note Shall be called only if ball collides with corresponding brick object.
     */
    void onHit();

private:
    float    mXDrawOffset;       ///< For positioning the brick on the screen.
    BrickDef mBrickDefinitions;  ///< Brick definitions that describes the brick.
                                 ///< All of brick objects have unique defs.
};

}  // namespace gui

#endif  // BREAKOUT_BRICK_HPP
