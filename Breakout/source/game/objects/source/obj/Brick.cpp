#include "Brick.hpp"

namespace gui
{

Brick::Brick(const sf::Texture& texture, BrickDef definition)
    : mXDrawOffset{ 20.0f }
    , mSprite{ texture }
    , mBrickDefinitions{ definition }
{
    mBrickDefinitions.globalBounds = mSprite.getLocalBounds();
    mSprite.setPosition(sf::Vector2f{ mBrickDefinitions.currentPosition.x * mBrickDefinitions.globalBounds.width
                                              + mBrickDefinitions.globalBounds.width + mXDrawOffset,
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

const Definitions& Brick::definitions() const
{
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

}  // namespace gui