#include "Paddle.hpp"

#include "ScreenDimensions.hpp"

namespace gui
{
Paddle::Paddle(const sf::Texture& texture, sf::Vector2f scalingFactor)
    : mPaddleDefinitions{ sf::Vector2f{ static_cast<float>(sScreenDimensions.width / 2),
                            static_cast<float>(sScreenDimensions.height - getGlobalBounds().height * 4) },
                          getGlobalBounds(),
                          scalingFactor }
{
    setPosition(mPaddleDefinitions.currentPosition);
}

Paddle::Paddle(Paddle&& other) noexcept
    : mPaddleDefinitions{ other.mPaddleDefinitions }
{
}

Paddle& Paddle::operator=(Paddle&& other) noexcept
{
    if (this != &other)
    {
        mPaddleDefinitions = other.mPaddleDefinitions;
    }
    return *this;
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

void Paddle::update()
{
    static_assert(sScreenDimensions.width != 0 && sScreenDimensions.height != 0);
    mPaddleDefinitions.currentPosition = getPosition();

    if (mPaddleDefinitions.currentPosition.x > sScreenDimensions.width)
    {
        setPosition(-getGlobalBounds().width, mPaddleDefinitions.currentPosition.y);
    }
    else if (mPaddleDefinitions.currentPosition.x < -getGlobalBounds().width)
    {
        setPosition(
                static_cast<float>(sScreenDimensions.width),
                static_cast<float>(mPaddleDefinitions.currentPosition.y));
    }

    move(mPaddleDefinitions.velocity);
}

}  // namespace gui