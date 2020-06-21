#ifndef BREAKOUT_ARROW_HPP
#define BREAKOUT_ARROW_HPP

#include <ostream>

#include "Widget.hpp"

class Arrow
    : public Widget
{
public:
    Arrow(sf::Texture& texture, const sf::RenderWindow& window);

    void updateMovement(const float& deltaTime);

    /**@copydoc Widget::update()*/
    void update(const float deltaTime) override;

    /**@copydoc Widget::bounds()*/
    sf::FloatRect bounds() const override;

    /**@copydoc Widget::type()*/
    WidgetType type() const override;

    /**@copydoc Widget::checkCollision()*/
    bool checkCollision(Widget& other) override;

    std::string widgetsFullName() {return "";};

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    sf::Sprite              mArrow;
    const sf::RenderWindow& mWindowRef;
};

#endif  // BREAKOUT_ARROW_HPP
