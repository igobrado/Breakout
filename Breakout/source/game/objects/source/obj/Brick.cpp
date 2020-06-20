#include "Brick.hpp"

namespace gui
{

Brick::Brick(const sf::Texture& texture, BrickDef definition)
    : sf::Sprite{ texture }
    , mXDrawOffset{ 0 }
    , mBrickDefinitions{ definition }
{
    mXDrawOffset = getTexture()->getSize().x;
    setPosition(
            sf::Vector2f{ mBrickDefinitions.currentPosition.x * getGlobalBounds().width + getGlobalBounds().width,
                          mBrickDefinitions.currentPosition.y * getGlobalBounds().height + getGlobalBounds().height });
}

bool Brick::shouldDestroy() const
{
    return mBrickDefinitions.brickStrength == 0;
}

void Brick::onHit()
{
    if (mBrickDefinitions.brickStrength != 0)
        --mBrickDefinitions.brickStrength;
}

bool Brick::isCollided(sf::FloatRect rect)
{
    if (getGlobalBounds().intersects(rect))
    {
        onHit();
        return true;
    }
    return false;
}

}  // namespace gui