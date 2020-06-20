#ifndef BREAKOUT_BALL_HPP
#define BREAKOUT_BALL_HPP

#include <SFML/Graphics.hpp>

namespace gui
{

/**
 * @brief Represents Ball object, wraps sf::Sprite class to abstract ball.
 *
 * @note implements interfaces: \see Movable \see Drawable
 */
class Ball : public sf::Sprite
{
public:
    explicit Ball(const sf::Texture& texture, sf::Vector2f scalingFactor);
    Ball(Ball&& other) noexcept = default;
    Ball& operator=(Ball&& other) noexcept = default;

    void resetBallPosition();

    void updateMovement(const float& deltaTime);

    /**
     * @brief Changes direction.
     *
     * Call this only if ball is actually intersected with paddle.
     */
    void onPaddleHit();

    /**
     * @brief Changes direction.
     *
     * Call this only if ball is actually intersected with brick.
     */
    void onBrickHit();

    /**
     * @brief Checks whether ball is colliding with given object.
     *
     * @param rect
     * @return true if ball and object collides, false if not.
     */
    bool isCollided(sf::FloatRect rect) const;

private:
    sf::Vector2f mMoveRegion;
    sf::Vector2f mDirection;
};

}  // namespace gui

#endif  // BREAKOUT_BALL_HPP
