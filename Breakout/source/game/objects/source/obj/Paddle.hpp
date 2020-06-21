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

    sf::Vector2f currentPosition;
    sf::Vector2f velocity;
    sf::Vector2f paddleSpeed;
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

    sf::FloatRect handlyCalculatedGlobalBounds() const;
protected:
    /**
     * @brief Updates paddle movement.
     *
     * @note Shall be called only by updateMovement.
     */
    void update();

private:
    PaddleDef mPaddleDefinitions;
};

}  // namespace gui
#endif  // BREAKOUT_PADDLE_HPP
