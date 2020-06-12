#include "Arrow.hpp"

Arrow::Arrow(sf::Texture& texture, const sf::RenderWindow& window)  //
    : mArrow{ texture }
    , mDefinitions{ { 200, 200 }, mArrow.getGlobalBounds(), { 0, 0 } }
    , mWindowRef{ window }
{
}

void Arrow::draw(sf::RenderWindow& window)
{
    window.draw(mArrow);
}

const Definitions& Arrow::definitions()
{
    mDefinitions.globalBounds = mArrow.getGlobalBounds();
    return mDefinitions;
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
