#ifndef BREAKOUT_BRICK_HPP
#define BREAKOUT_BRICK_HPP

#include <SFML/Graphics.hpp>

namespace gui
{

enum class BrickColor
{
    RED   = 0,
    BLUE  = 1,
    GREEN = 2,
    CYAN  = 3
};

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
    BrickDef(std::uint16_t brickStrength, BrickColor color, sf::Vector2f scalingFactor)
        : brickStrength(brickStrength)
        , color(color)
    {
    }

    BrickDef(
            sf::Vector2f  currentPosition,
            sf::FloatRect globalBounds,
            std::uint16_t brickStrength,
            BrickColor    color,
            sf::Vector2f  scalingFactor)  //
        : brickStrength{ brickStrength }
        , color{ color }
        , currentPosition{currentPosition}
    {
    }

    std::uint16_t brickStrength;
    BrickColor    color;
    sf::Vector2f  currentPosition;
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
    Brick(Brick&& other) noexcept;
    Brick& operator=(Brick&& other) noexcept;

    /**
     * @brief Checks whether brick strength came down to 0.
     *
     * @note If Brick strength comes to 0, brick shall destroy.
     *
     * @return true if brick strength is 0 false if not.
     */
    bool shouldDestroy() const;

    /**
     * @brief Decreases bricks life by one.
     *
     * @note Shall be called only if ball collides with corresponding brick object.
     */
    void onHit();

    bool isCollided(sf::FloatRect rect);
private:
    float      mXDrawOffset;
    BrickDef   mBrickDefinitions;
};

}  // namespace gui

#endif  // BREAKOUT_BRICK_HPP
