#include "WriteableTextbox.hpp"

#include "ScreenDimensions.hpp"

WriteableTextbox::WriteableTextbox(
        std::uint32_t coordX,
        std::uint32_t coordY,
        sf::Font&     font,
        sf::Color     color,
        const char*   text,
        std::uint64_t size)
    : Textbox(coordX, coordY, font, color, text, size)
    , mDefaultSize{ 400, 80 }
{
    mInputRect.setOutlineColor(sf::Color::Red);
    mInputRect.setOutlineThickness(1.0f);
    mInputRect.setSize(mDefaultSize);
    mInputRect.setFillColor(sf::Color::White);

    if (!coordX && !coordY)
    {
        coordX = ::sScreenDimensions.width / 2. - mDefaultSize.x / 2.;
        coordY = ::sScreenDimensions.height / 2. - mDefaultSize.y / 2.;
    }

    mText.setPosition(coordX, coordY);
    mInputRect.setPosition(static_cast<float>(coordX), static_cast<float>(coordY));
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

void WriteableTextbox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mInputRect, states);
    Textbox::draw(target, states);
}
