#ifndef BREAKOUT_BRICK_HPP
#define BREAKOUT_BRICK_HPP

#include "Drawable.hpp"

namespace gui
{
struct BrickDef
{
    BrickDef()  //
        : brickStrength{ 0U }
        , position{ 0.0f, 0.0f }
        , bounds{ 0.0f, 0.0f, 0.0f, 0.0f }
    {
    }
    std::uint16_t brickStrength;
    sf::Vector2f  position;
    sf::FloatRect bounds;
};

class Brick : public Drawable
{
public:
    Brick(const sf::Texture& texture, BrickDef definition);
    const BrickDef& properties() const;
    void draw(sf::RenderWindow& window) override;

private:
    float      mXDrawOffset;
    sf::Sprite mSprite;
    BrickDef   mBrickDefinitons;
};

}  // namespace gui

#endif  // BREAKOUT_BRICK_HPP
