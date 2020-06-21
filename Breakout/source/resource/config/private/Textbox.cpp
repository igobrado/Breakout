#include "Textbox.hpp"

Textbox::Textbox(
        std::uint32_t coordX,
        std::uint32_t coordY,
        sf::Font&     font,
        sf::Color     color,
        const char*   text,
        std::uint64_t size)  //
    : mText{ text, font }
    , mSize{ size }
    , mColor{ color }
{
    mText.setPosition(static_cast<float>(coordX), static_cast<float>(coordY));
    mText.setCharacterSize(60);
    mText.setFillColor(color);
}

Textbox::Textbox(Textbox&& other) noexcept  //
    : mText{ std::move(other.mText) }
    , mSize{ other.mSize }
    , mColor{ other.mColor }
{
}

Textbox& Textbox::operator=(Textbox&& other)
{
    if (this != &other)
    {
        mText  = std::move(other.mText);
        mSize  = other.mSize;
        mColor = other.mColor;
    }
    return *this;
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

void Textbox::onFocus()
{
    // TODO: Magic number, remove
    mText.setFillColor(sf::Color{ 0, 160, 255 });
}

void Textbox::onFocusEnded()
{
    mText.setFillColor(mColor);
}

bool Textbox::checkCollision(Widget& other)
{
    return bounds().intersects(other.bounds());
}

void Textbox::setString(const sf::String& stringToSet)
{
    mText.setString(stringToSet);
}

void Textbox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mText, states);
}
