#include "WriteableTextbox.hpp"

WriteableTextbox::WriteableTextbox(
        std::uint32_t coordX,
        std::uint32_t coordY,
        sf::Font&     font,
        sf::Color     color,
        const char*   text,
        std::uint64_t size)
    : Textbox(coordX, coordY, font, color,  text, size)
{
    mInputRect.setPosition(static_cast<float>(coordX), static_cast<float>(coordY));
    mInputRect.setOutlineColor(sf::Color::Red);
    mInputRect.setOutlineThickness(1.0f);
    mInputRect.setSize({ 400, 80 });
    mInputRect.setFillColor(sf::Color::White);
}

sf::FloatRect WriteableTextbox::bounds() const
{
    return mInputRect.getGlobalBounds();
}

Widget::WidgetType WriteableTextbox::type() const
{
    return WidgetType::TEXTBOX;
}

bool WriteableTextbox::checkCollision(Widget& other)
{
    return bounds().intersects(other.bounds());
}
