#ifndef BREAKOUT_PADDLE_HPP
#define BREAKOUT_PADDLE_HPP

#include "Drawable.hpp"
#include "Movable.hpp"

namespace gui
{
struct PaddleDef : public Definitions
{
    PaddleDef(sf::Vector2f currentPosition, sf::FloatRect globalBounds, sf::Vector2f scalingFactor)
        : Definitions{ currentPosition, globalBounds, scalingFactor }
        , velocity{ 0.0f, 0.0f }
        , paddleSpeed{ 300.0f, 0.0f }
    {
    }

    sf::Vector2f       velocity;
    const sf::Vector2f paddleSpeed;
};

class Paddle
    : public ::Movable
    , public ::Drawable
{
public:
    Paddle(const sf::Texture& texture, sf::Vector2f scalingFactor);
    Paddle(Paddle&& other) noexcept;

    void draw(sf::RenderWindow& window) override;

    /**@copydoc Movable::updateMovement()*/
    void updateMovement(const float& deltaTime) override;

    /**@copydoc Movable::definitions()*/
    const Definitions& definitions() override;

protected:
    void update();

private:
    sf::Sprite mSprite;
    PaddleDef  mPaddleDefinitions;
};

}  // namespace gui
#endif  // BREAKOUT_PADDLE_HPP
