#ifndef BREAKOUT_BALL_HPP
#define BREAKOUT_BALL_HPP

#include "Drawable.hpp"
#include "Movable.hpp"

namespace gui
{
/**
 * @brief Holds ball important data.
 */
struct BallDefs : public Definitions
{
    BallDefs(
            sf::FloatRect globalBounds,
            sf::Vector2f  currentPosition,
            sf::Vector2f  lastPosition,
            sf::Vector2f  clientZone,
            sf::Vector2f  direction,
            sf::Vector2f  scalingFactor)
        : Definitions{ currentPosition, globalBounds, scalingFactor }
        , lastPosition{ lastPosition }
        , clientZone{ clientZone }
        , direction{ direction }
    {
    }

    sf::Vector2f lastPosition;
    sf::Vector2f clientZone;
    sf::Vector2f direction;
};

/**
 * @brief Represents Ball object, wraps sf::Sprite class to abstract ball.
 *
 * @note implements interfaces: \see Movable \see Drawable
 */
class Ball
    : public Movable  //
    , public Drawable
{
public:
    explicit Ball(const sf::Texture& texture, sf::Vector2f scalingFactor);
    Ball(Ball&& other) noexcept;

    void draw(sf::RenderWindow& window) override;

    /**@copydoc Movable::updateMovement()*/
    void updateMovement(const float& deltaTime) override;

    /**@copydoc Movable::definitions()*/
    const Definitions& definitions() override;

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
    sf::Sprite mSprite;
    BallDefs   mBallDefinitions;
};

}  // namespace gui

#endif  // BREAKOUT_BALL_HPP
