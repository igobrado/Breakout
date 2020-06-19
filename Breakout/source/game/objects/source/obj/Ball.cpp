#include "Ball.hpp"

#include <SFML/Graphics/Glsl.hpp>
#include <cmath>
#include <random>

#include "ScreenDimensions.hpp"
namespace gui
{

Ball::Ball(const sf::Texture& texture, sf::Vector2f scalingFactor)  //
    : mSprite{ texture }
    , mBallDefinitions{ { mSprite.getLocalBounds() },
                        { 500.0f, 500.0f },
                        { 0.0f, 0.0f },
                        { sScreenDimensions.width - mSprite.getLocalBounds().width,
                          sScreenDimensions.height - mSprite.getLocalBounds().height },
                        { 7.0f, 7.0f },
                        scalingFactor }
{
    mSprite.setScale(mBallDefinitions.scalingFactor);
    mSprite.setPosition(600, 600);
    mBallDefinitions.lastPosition = mSprite.getPosition();
}

Ball::Ball(Ball&& other) noexcept  //
    : mSprite{ std::move(other.mSprite) }
    , mBallDefinitions{ other.mBallDefinitions }
{
}

Ball& Ball::operator=(Ball&& other) noexcept
{
    if (this != &other)
    {
        mSprite          = std::move(other.mSprite);
        mBallDefinitions = other.mBallDefinitions;
    }
    return *this;
}

void Ball::resetBallPosition()
{
    mSprite.setPosition(600, 600);
}

void Ball::draw(sf::RenderWindow& window)
{
    window.draw(mSprite);
}

void Ball ::updateMovement(const float& deltaTime)
{
    mBallDefinitions.globalBounds = mSprite.getGlobalBounds();

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
    mBallDefinitions.globalBounds = mSprite.getGlobalBounds();
    return mBallDefinitions;
}

void Ball::onPaddleHit()
{
    std::random_device                 rd;
    std::mt19937                       mt{ rd() };
    std::uniform_int_distribution<int> dist{ 3, 7 };

    mBallDefinitions.direction.y = -(dist(mt));
}

void Ball::onBrickHit()
{
    mBallDefinitions.direction = -mBallDefinitions.direction;
}

bool Ball::isCollided(sf::FloatRect rect) const
{
    return mSprite.getGlobalBounds().intersects(rect);
}
}  // namespace gui