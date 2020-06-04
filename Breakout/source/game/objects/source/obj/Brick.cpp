#include "Brick.hpp"

namespace gui
{

Brick::Brick(const sf::Texture& texture, BrickDef definition)
    : mXDrawOffset{ 20.0f }
    , mSprite{ texture }
    , mBrickDefinitions{ definition }
{
    mSprite.setPosition(sf::Vector2f{ definition.currentPosition.x * definition.globalBounds.width
                                              + definition.globalBounds.width + mXDrawOffset,
                                      definition.currentPosition.y * definition.globalBounds.height
                                              + definition.globalBounds.height });
}

const Definitions& Brick::definitions() const
{
    return mBrickDefinitions;
}

void Brick::draw(sf::RenderWindow& window)
{
    window.draw(mSprite);
}

}  // namespace gui