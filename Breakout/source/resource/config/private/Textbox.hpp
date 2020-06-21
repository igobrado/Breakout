#ifndef BREAKOUT_TEXTBOX_HPP
#define BREAKOUT_TEXTBOX_HPP
#include "Widget.hpp"

class Textbox : public Widget
{
public:
    Textbox(std::uint32_t coordX,
            std::uint32_t coordY,
            sf::Font&     font,
            sf::Color     color,
            const char*   text = "",
            std::uint64_t size = 60);

    Textbox(Textbox&& other) noexcept;
    Textbox& operator=(Textbox&& other) noexcept;

    ~Textbox() override = default;

    std::string widgetsFullName();

    /**@copydoc Widget::bounds()*/
    sf::FloatRect bounds() const override;

    /**@copydoc Widget::type()*/
    Widget::WidgetType type() const override;

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

    /**
     * @brief Sets the text that will be printed to the screen.
     *
     * @param stringToSet new string that will printed to screen.
     */
    void setString(const sf::String& stringToSet);

protected:
    sf::Text      mText;
    std::uint64_t mSize;
    sf::Color     mColor;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif  // BREAKOUT_TEXTBOX_HPP
