#include "Ball.hpp"

#include <SFML/Graphics/Glsl.hpp>
#include <cmath>
#include <random>

#include "ScreenDimensions.hpp"
namespace gui
{

Ball::Ball(const sf::Texture& texture)  //
    : sf::Sprite{ texture }
    , mMoveRegion{ sScreenDimensions.width - getGlobalBounds().width,
                   sScreenDimensions.height - getGlobalBounds().height }
    , mDirection{ 7.0f, 7.0f }
{
    setPosition(600, 600);
}

void Ball::resetBallPosition()
{
    setPosition(600, 600);
}

void Ball::updateMovement(const float& deltaTime)
{
    auto currentPosition = getPosition();
    if (currentPosition.x < 0 || currentPosition.x > mMoveRegion.x)
    {
        mDirection.x = -mDirection.x;
    }
    else if (currentPosition.y < 0 || currentPosition.y > mMoveRegion.y)
    {
        mDirection.y = -mDirection.y;
    }
    move(mDirection);
}

void Ball::onPaddleHit()
{
    std::random_device                 rd;
    std::mt19937                       mt{ rd() };
    std::uniform_int_distribution<int> dist{ 3, 7 };

    mDirection.y = -(dist(mt));
}

void Ball::onBrickHit()
{
    mDirection = -mDirection;
}

bool Ball::isCollided(sf::FloatRect rect)
{
    return getTransform().transformRect(getLocalBounds()).intersects(rect);
}

sf::FloatRect Ball::handlyCalculatedGlobalBounds() const
{
    return getTransform().transformRect(getLocalBounds());
}

}  // namespace gui