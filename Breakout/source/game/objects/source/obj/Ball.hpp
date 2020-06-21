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
    Ball(const sf::Texture& texture);

    /**
     * @brief Resets ball position to default one.
     */
    void resetBallPosition();

    /**
     * @brief Updates the ball movement, and changes it according to collision with screen size.
     *
     * @param deltaTime
     */
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
    bool isCollided(sf::FloatRect rect);

    /**
     * @brief Calculates globalBounds on more proper way provided from SFML library.
     *
     * @return
     */
    sf::FloatRect handlyCalculatedGlobalBounds() const;

private:
    sf::Vector2f mMoveRegion;  ///< Region where ball can move (that is the game screen - width / height).
    sf::Vector2f mDirection;   ///< Direction of the ball, when ball hits the brick direction swaps. When ball hits the
                               ///< paddle, its calculated randomly.
};

}  // namespace gui

#endif  // BREAKOUT_BALL_HPP
