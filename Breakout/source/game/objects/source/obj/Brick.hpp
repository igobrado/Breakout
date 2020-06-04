#ifndef BREAKOUT_BRICK_HPP
#define BREAKOUT_BRICK_HPP

#include "Drawable.hpp"
#include "Movable.hpp"
namespace gui
{

/**
 * @brief Holds ball important data.
 */
struct BrickDef : public Definitions
{
    BrickDef(sf::Vector2f currentPosition, sf::FloatRect globalBounds, std::uint16_t brickStrength)  //
        : Definitions{ currentPosition, globalBounds }
        , brickStrength{ brickStrength }
    {
    }
    std::uint16_t brickStrength;
};

/**
 * @brief Represents Ball object, wraps sf::Sprite class to abstract brick.
 *
 * @note implements interfaces: \see Movable \see Drawable
 */
class Brick : public Drawable
{
public:
    Brick(const sf::Texture& texture, BrickDef definition);

    /**@copydoc Movable::definitions()*/
    const Definitions& definitions() const;

    /**@copydoc Movable::draw()*/
    void               draw(sf::RenderWindow& window) override;

private:
    float      mXDrawOffset;
    sf::Sprite mSprite;
    BrickDef   mBrickDefinitions;
};

}  // namespace gui

#endif  // BREAKOUT_BRICK_HPP
