#ifndef BREAKOUT_ARROW_HPP
#define BREAKOUT_ARROW_HPP

#include <ostream>

#include "Movable.hpp"
#include "Widget.hpp"

class Arrow
    : public Widget
    , public Movable
{
public:
    Arrow(sf::Texture& texture, const sf::RenderWindow& window);

    /**@copydoc Drawable::draw()*/
    void draw(sf::RenderWindow& window) override;

    /**@copydoc Movable::updateMovement()*/
    void updateMovement(const float& deltaTime) override;

    /**@copydoc Widget::update()*/
    void update(const float deltaTime) override;

    /**@copydoc Widget::bounds()*/
    sf::FloatRect bounds() const override;

    /**@copydoc Widget::type()*/
    WidgetType type() const override;

    /**@copydoc Widget::checkCollision()*/
    bool checkCollision(Widget& other) override;

    std::string widgetsFullName() {return "";};

public:
    sf::Sprite              mArrow;
    const sf::RenderWindow& mWindowRef;
};

#endif  // BREAKOUT_ARROW_HPP
