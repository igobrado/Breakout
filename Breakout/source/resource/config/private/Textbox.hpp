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
            bool          writeable     = false,
            std::uint64_t size          = 60);

    Textbox(Textbox&& other) noexcept;
    ~Textbox() override = default;

    std::string widgetsFullName();

    /**@copydoc Widget::bounds()*/
    sf::FloatRect bounds() const override;

    /**@copydoc Widget::type()*/
    Widget::WidgetType type() const override;

    /**@copydoc Drawable::draw()*/
    void draw(sf::RenderWindow& window) override;

    /**@copydoc Widget::update()*/
    void update(const float deltaTime) override{};

    /**
     * @brief Changes the colour of text to lighter one.
     */
    void onFocus() override;

    /**
     * @brief Reset's colour to default one.
     */
    void onFocusEnded() override;

    /**@copydoc Widget::checkCollision()*/
    bool checkCollision(Widget& other) override;

    void setString(const sf::String& stringToSet)
    {
        mText.setString(stringToSet);
    }

private:
    sf::RectangleShape mInputRect;

    sf::Text   mText;
    const bool mUseBackground;
    const bool mWriteable;

    const std::uint64_t mSize;
};

#endif  // BREAKOUT_TEXTBOX_HPP
