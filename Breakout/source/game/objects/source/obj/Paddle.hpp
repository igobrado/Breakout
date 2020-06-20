#ifndef BREAKOUT_PADDLE_HPP
#define BREAKOUT_PADDLE_HPP

#include <SFML/Graphics.hpp>

namespace gui
{
struct PaddleDef
{
    PaddleDef(sf::Vector2f currentPosition, sf::FloatRect globalBounds, sf::Vector2f scalingFactor)
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
    Paddle(const sf::Texture& texture, sf::Vector2f scalingFactor);

    Paddle(Paddle&& other) noexcept;
    Paddle& operator=(Paddle&& other) noexcept;

    /**@copydoc Movable::updateMovement()*/
    void updateMovement(const float& deltaTime);

protected:
    /**
     * @brief Updates paddle movement.
     *
     * @note Shall be called only by updateMovement.
     */
    void update();

private:
    PaddleDef  mPaddleDefinitions;
};

}  // namespace gui
#endif  // BREAKOUT_PADDLE_HPP
