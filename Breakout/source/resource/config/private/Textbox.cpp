#include "Textbox.hpp"

Textbox::Textbox(
        std::uint32_t coordX,
        std::uint32_t coordY,
        sf::Font&     font,
        const char*   text,
        bool          useBackground,
        bool          writeable)  //
    : mSprite{}
    , mText{ text, font }
    , mUseBackground{ useBackground }
    , mWriteable{ writeable }
{
    mText.setPosition(static_cast<float>(coordX), static_cast<float>(coordY));
    mText.setFillColor(sf::Color::Blue);
    mText.setOutlineColor(sf::Color::Black);
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