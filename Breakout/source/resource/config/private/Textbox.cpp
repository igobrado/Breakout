#include "Textbox.hpp"

Textbox::Textbox(
        std::uint32_t coordX,
        std::uint32_t coordY,
        sf::Font&     font,
        const char*   text,
        bool          useBackground,
        bool          writeable,
        std::uint64_t size)  //
    : mInputRect{}
    , mText{ text, font }
    , mUseBackground{ useBackground }
    , mWriteable{ writeable }
    , mSize{ size }
{
    if (mUseBackground)
    {
        mInputRect.setPosition(static_cast<float>(coordX), static_cast<float>(coordY));
        mInputRect.setSize({ 400, 80 });
        mInputRect.setFillColor(sf::Color::White);
    }

    mText.setPosition(static_cast<float>(coordX), static_cast<float>(coordY));
    mText.setCharacterSize(60);
    mText.setFillColor(sf::Color::Blue);
    mText.setOutlineColor(sf::Color::Red);
}

Textbox::Textbox(Textbox&& other) noexcept
    : mInputRect{ std::move(other.mInputRect) }
    , mText{ std::move(other.mText) }
    , mUseBackground{ other.mUseBackground }
    , mWriteable{ other.mWriteable }
    , mSize{ other.mSize }
{
}

std::string Textbox::widgetsFullName()
{
    return std::string{ mText.getString().begin(), mText.getString().end() };  // return mText.getString();
}

sf::FloatRect Textbox::bounds() const
{
    if (mUseBackground)  ///< If background is used,then we need size of input rect, no text.
    {
        return mInputRect.getGlobalBounds();
    }
    return mText.getGlobalBounds();
}

Widget::WidgetType Textbox::type() const
{
    return Widget::WidgetType::TEXTBOX;
}

void Textbox::draw(sf::RenderWindow& window)
{
    if (mUseBackground)
    {
        window.draw(mInputRect);
    }
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
