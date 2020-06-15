#include "Textbox.hpp"

Textbox::Textbox(
        std::uint32_t coordX,
        std::uint32_t coordY,
        sf::Font&     font,
        const char*   text,
        std::uint64_t size)  //
    : mText{ text, font }
    , mSize{ size }
{

    mText.setPosition(static_cast<float>(coordX), static_cast<float>(coordY));
    mText.setCharacterSize(60);
    mText.setFillColor(sf::Color::Blue);
    mText.setOutlineColor(sf::Color::Red);
}

Textbox::Textbox(Textbox&& other) noexcept
    : mText{ std::move(other.mText) }
    , mSize{ other.mSize }
{
}

std::string Textbox::widgetsFullName()
{
    return std::string{ mText.getString().begin(), mText.getString().end() };
}

sf::FloatRect Textbox::bounds() const
{
    return mText.getGlobalBounds();
}

Widget::WidgetType Textbox::type() const
{
    return Widget::WidgetType::TEXTBOX;
}

void Textbox::draw(sf::RenderWindow& window)
{
    window.draw(mText);
}

void Textbox::onFocus()
{
    mText.setFillColor(sf::Color{ 0, 160, 255 });
}

void Textbox::onFocusEnded()
{
    mText.setFillColor(sf::Color::Blue);
}

bool Textbox::checkCollision(Widget& other)
{
    return bounds().intersects(other.bounds());
}

void Textbox::setString(const sf::String& stringToSet)
{
    mText.setString(stringToSet);
}
