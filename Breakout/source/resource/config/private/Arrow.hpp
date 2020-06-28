#ifndef BREAKOUT_ARROW_HPP
#define BREAKOUT_ARROW_HPP

#include <ostream>

#include "Widget.hpp"

class Arrow : public Widget
{
public:
    Arrow(sf::Texture& texture, const sf::RenderWindow& window);

    /**@copydoc Widget::update()*/
    void update(const float deltaTime) override;

    /**@copydoc Widget::bounds()*/
    sf::FloatRect bounds() const override;

    /**@copydoc Widget::type()*/
    WidgetType type() const override;

    /**@copydoc Widget::checkCollision()*/
    bool checkCollision(Widget& other) override;

    /**
     * @note Returns empty string since this method is not relevant for this object type.
     */
    std::string widgetsFullName();

protected:
    /**
     * @brief Updates the Arrow's movement.
     *
     * @param deltaTime
     */
    void updateMovement(const float& deltaTime);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    sf::Sprite              mArrow;      ///< Sprite object of the arrow that shall be displayed to the screen.
    const sf::RenderWindow& mWindowRef;  ///< Render window ref. Arrow updates the position
                                         ///< of itself with api provided from this ref.
};

#endif  // BREAKOUT_ARROW_HPP
