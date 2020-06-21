#ifndef BREAKOUT_PADDLE_HPP
#define BREAKOUT_PADDLE_HPP

#include <SFML/Graphics.hpp>

namespace gui
{
struct PaddleDef
{
    explicit PaddleDef(sf::Vector2f currentPosition)
        : currentPosition{ currentPosition }
        , velocity{ 0.0f, 0.0f }
        , paddleSpeed{ 300.0f, 0.0f }
    {
    }

    sf::Vector2f currentPosition;  ///< Current position of the paddle.
    sf::Vector2f velocity;         ///< Velocity of the paddle.
    sf::Vector2f paddleSpeed;      ///< Paddle's speed.
};

class Paddle : public sf::Sprite
{
public:
    Paddle(const sf::Texture& texture);

    /**
     * @brief Updates the ball movement, and changes it according to collision with screen size.
     *
     * @param deltaTime
     */
    void updateMovement(const float& deltaTime);

    /**
     * @brief Calculates globalBounds on more proper way provided from SFML library.
     *
     * @return
     */
    sf::FloatRect handlyCalculatedGlobalBounds() const;

protected:
    /**
     * @brief Updates paddle movement.
     *
     * @note Shall be called only by updateMovement.
     */
    void update();

private:
    PaddleDef mPaddleDefinitions;  ///< Paddle definitions. Every paddle object has unique definitions.
};

}  // namespace gui
#endif  // BREAKOUT_PADDLE_HPP
