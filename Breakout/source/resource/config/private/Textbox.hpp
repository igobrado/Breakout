#ifndef BREAKOUT_TEXTBOX_HPP
#define BREAKOUT_TEXTBOX_HPP
#include "Widget.hpp"

class Textbox : public Widget
{
public:
    explicit Textbox(
            std::uint32_t coordX,
            std::uint32_t coordY,
            sf::Font&     font,
            const char*   text          = "",
            bool          useBackground = false,
            bool          writeable     = false);
    ~Textbox() override = default;

    /**@copydoc Drawable::draw()*/
    void draw(sf::RenderWindow& window) override;

    /**
     * @brief Changes the colour of text to lighter one.
     */
    void onFocus();

private:
    sf::Sprite mSprite;
    sf::Text   mText;
    const bool mUseBackground;
    const bool mWriteable;
};

#endif  // BREAKOUT_TEXTBOX_HPP
