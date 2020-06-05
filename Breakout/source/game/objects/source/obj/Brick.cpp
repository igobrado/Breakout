#include "Brick.hpp"

namespace gui
{

Brick::Brick(const sf::Texture& texture, BrickDef definition)
    : mXDrawOffset{ 0 }
    , mSprite{ texture }
    , mBrickDefinitions{ definition }
{
    mSprite.setScale(mBrickDefinitions.scalingFactor);
    mBrickDefinitions.globalBounds = mSprite.getGlobalBounds();
    mXDrawOffset = mSprite.getTexture()->getSize().x;
    mSprite.setPosition(sf::Vector2f{ mBrickDefinitions.currentPosition.x * mBrickDefinitions.globalBounds.width
                                              + mBrickDefinitions.globalBounds.width,
                                      mBrickDefinitions.currentPosition.y * mBrickDefinitions.globalBounds.height
                                              + mBrickDefinitions.globalBounds.height });
    mBrickDefinitions.currentPosition = mSprite.getPosition();

}

Brick::Brick(Brick&& other) noexcept
    : mXDrawOffset{ other.mXDrawOffset }
    , mSprite{ std::move(other.mSprite) }
    , mBrickDefinitions{ other.mBrickDefinitions }
{
}

Brick& Brick::operator=(Brick&& other) noexcept
{
    if (this != &other)
    {
        mXDrawOffset      = other.mXDrawOffset;
        mSprite           = std::move(other.mSprite);
        mBrickDefinitions = other.mBrickDefinitions;
    }
    return *this;
}

const Definitions& Brick::definitions()
{
    mBrickDefinitions.globalBounds = mSprite.getGlobalBounds();
    return mBrickDefinitions;
}

void Brick::draw(sf::RenderWindow& window)
{
    window.draw(mSprite);
}

bool Brick::shouldDestroy() const
{
    return mBrickDefinitions.brickStrength == 0;
}

void Brick::onHit()
{
    --mBrickDefinitions.brickStrength;
}

}  // namespace gui