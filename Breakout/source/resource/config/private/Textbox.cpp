#include "Textbox.hpp"

Textbox::Textbox(
        std::uint32_t coordX,
        std::uint32_t coordY,
        sf::Font&     font,
        const char*   text,
        bool          useBackground,
        bool          writeable,
        std::uint64_t size)  //
    : mSprite{}
    , mText{ text, font }
    , mUseBackground{ useBackground }
    , mWriteable{ writeable }
    , mSize{ size }
{
    mText.setPosition(static_cast<float>(coordX), static_cast<float>(coordY));
    mText.setCharacterSize(60);
    mText.setFillColor(sf::Color::Green);
    mText.setOutlineColor(sf::Color::Red);
}

void Textbox::draw(sf::RenderWindow& window)
{
    if (mUseBackground)
    {
        window.draw(mSprite);
    }
    window.draw(mText);
}

void Textbox::onFocus()
{
    mText.setFillColor(sf::Color{ 0, 160, 255 });
}