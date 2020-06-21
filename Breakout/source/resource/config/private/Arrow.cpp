#include "Arrow.hpp"

Arrow::Arrow(sf::Texture& texture, const sf::RenderWindow& window)  //
    : mArrow{ texture }
    , mWindowRef{ window }
{
}

void Arrow::updateMovement(const float& deltaTime)
{
    mArrow.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(mWindowRef)));
}

sf::FloatRect Arrow::bounds() const
{
    return mArrow.getGlobalBounds();
}

Widget::WidgetType Arrow::type() const
{
    return WidgetType::ARROW;
}

void Arrow::update(const float deltaTime)
{
    updateMovement(deltaTime);
}

bool Arrow::checkCollision(Widget& other)
{
    return mArrow.getGlobalBounds().intersects(other.bounds());
}

void Arrow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mArrow, states);
}

std::string Arrow::widgetsFullName()
{
    return "";
}
