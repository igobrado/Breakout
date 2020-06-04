#include "Brick.hpp"

namespace gui
{

Brick::Brick(const sf::Texture& texture, BrickDef definition)
    : mXDrawOffset{ 20.0f }
    , mSprite{ texture }
    , mBrickDefinitons{ definition }
{
    mSprite.setPosition(
            sf::Vector2f{ definition.position.x * definition.bounds.width + definition.bounds.width + mXDrawOffset,
                          definition.position.y * definition.bounds.height + definition.bounds.height });
}

const BrickDef& Brick::properties() const
{
    return mBrickDefinitons;
}

void Brick::draw(sf::RenderWindow& window)
{
    window.draw(mSprite);
}

}  // namespace gui