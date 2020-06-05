#include "Paddle.hpp"

#include "ScreenDimensions.hpp"

namespace gui
{
Paddle::Paddle(const sf::Texture& texture, sf::Vector2f scalingFactor)
    : mSprite{ texture }
    , mPaddleDefinitions{ { sScreenDimensions.width / 2,
                            sScreenDimensions.height - mSprite.getGlobalBounds().height * 4 },
                          mSprite.getGlobalBounds(),
                          scalingFactor }
{
    mSprite.setPosition(mPaddleDefinitions.currentPosition);
}

Paddle::Paddle(Paddle&& other) noexcept
    : mSprite{ std::move(other.mSprite) }
    , mPaddleDefinitions{ other.mPaddleDefinitions }
{
}

Paddle& Paddle::operator=(Paddle&& other) noexcept
{
    if (this != &other)
    {
        mSprite            = std::move(other.mSprite);
        mPaddleDefinitions = other.mPaddleDefinitions;
    }
    return *this;
}

void Paddle::draw(sf::RenderWindow& window)
{
    window.draw(mSprite);
}

void Paddle::updateMovement(const float& deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        mPaddleDefinitions.velocity.x = -(deltaTime * mPaddleDefinitions.paddleSpeed.x);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        mPaddleDefinitions.velocity.x = deltaTime * mPaddleDefinitions.paddleSpeed.x;
    }
    else
    {
        mPaddleDefinitions.velocity.x = 0.0f;
    }
    update();
}

const Definitions& Paddle::definitions()
{
    mPaddleDefinitions.currentPosition = mSprite.getPosition();
    mPaddleDefinitions.globalBounds    = mSprite.getGlobalBounds();
    return mPaddleDefinitions;
}

void Paddle::update()
{
    static_assert(sScreenDimensions.width != 0 && sScreenDimensions.height != 0);
    mPaddleDefinitions.currentPosition = mSprite.getPosition();

    if (mPaddleDefinitions.currentPosition.x > sScreenDimensions.width)
    {
        mSprite.setPosition(-mPaddleDefinitions.globalBounds.width, mPaddleDefinitions.currentPosition.y);
    }
    else if (mPaddleDefinitions.currentPosition.x < -mPaddleDefinitions.globalBounds.width)
    {
        mSprite.setPosition(sScreenDimensions.width, mPaddleDefinitions.currentPosition.y);
    }
    mSprite.move(mPaddleDefinitions.velocity);
}

}  // namespace gui