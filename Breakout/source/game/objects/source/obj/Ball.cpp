#include "Ball.hpp"

#include <cmath>

#include "ScreenDimensions.hpp"

namespace gui
{

Ball::Ball(const sf::Texture& texture)  //
    : mSprite{ texture }
    , mBallDefinitions{ { mSprite.getLocalBounds() },
                        { 500.0f, 500.0f },
                        { 0.0f, 0.0f },
                        { sScreenDimensions.width - mSprite.getLocalBounds().width,
                          sScreenDimensions.height - mSprite.getLocalBounds().height },
                        { 7.0f, 7.0f } }
{
}

Ball::Ball(Ball&& other) noexcept  //
    : mSprite{ std::move(other.mSprite) }
    , mBallDefinitions{ other.mBallDefinitions }
{
}

void Ball::draw(sf::RenderWindow& window)
{
    window.draw(mSprite);
}

void Ball ::updateMovement(const float& deltaTime)
{
    mBallDefinitions.lastPosition    = mBallDefinitions.currentPosition;
    mBallDefinitions.currentPosition = mSprite.getPosition();

    // IMHO pretty self explanatory.
    // If ball is trying to not be inside of game screen then reverse it by 45 angles in another angle.
    if (mBallDefinitions.currentPosition.x < 0 || mBallDefinitions.currentPosition.x > mBallDefinitions.clientZone.x)
    {
        mBallDefinitions.direction.x = -mBallDefinitions.direction.x;
    }
    else if (
            mBallDefinitions.currentPosition.y < 0
            || mBallDefinitions.currentPosition.y > mBallDefinitions.clientZone.y)
    {
        mBallDefinitions.direction.y = -mBallDefinitions.direction.y;
    }
    mSprite.move(mBallDefinitions.direction);
}

const Definitions& Ball::definitions()
{
    return mBallDefinitions;
}

void Ball::onPaddleHit()
{
    // This could be solved on way to just negating x and y directions. If that was implemented then ball should return
    // in 90 degrees angle. ( nah good )
    sf::Vector2f intersectPoint = mSprite.getPosition();
    auto         intersectAngle = 2
                          * (std::atan(
                                  intersectPoint.y
                                  / (intersectPoint.x  //
                                     + (sqrt(pow(intersectPoint.x, 2) + pow(intersectPoint.y, 2))))));

    intersectAngle           = intersectAngle * 180 / 3.14;
    const auto bouncingAngle = 180 - intersectAngle;  ///< In theory, without speed, nor wind and extern dependencies
                                                      ///< If ball hits onto wall in 90 angle,
                                                      ///< then it shall return the same way.
    const auto relativePointX = intersectPoint.x - mBallDefinitions.lastPosition.x;  ///< Relative to paddle.
    const auto relativePointY = intersectPoint.y - mBallDefinitions.lastPosition.y;

    sf::Vector2f result{ 0.0f, 0.0f };
    result.y = relativePointX * std::cos(bouncingAngle) - relativePointY * std::sin(bouncingAngle);
    result.x = relativePointX * std::sin(bouncingAngle) + relativePointY * std::cos(bouncingAngle);

    result.x *= 0.532;  ///< Magic number, I know. It's shall be put to some kind of constexpr.
    result.y *= 0.532;  ///< It's used for slowdown ball.

    mBallDefinitions.direction = result;
}

void Ball::onBrickHit()
{
    mBallDefinitions.direction = -mBallDefinitions.direction;
}

bool Ball::isCollided(sf::FloatRect rect) const
{
    return mSprite.getLocalBounds().intersects(rect);
}
}  // namespace gui