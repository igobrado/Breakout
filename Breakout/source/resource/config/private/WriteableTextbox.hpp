#ifndef BREAKOUT_WRITEABLETEXTBOX_HPP
#define BREAKOUT_WRITEABLETEXTBOX_HPP

#include "Textbox.hpp"

class WriteableTextbox : public Textbox
{
public:
    WriteableTextbox(
            std::uint32_t coordX,
            std::uint32_t coordY,
            sf::Font&     font,
            sf::Color     color,
            const char*   text = "",
            std::uint64_t size = 60);

    /**@copydoc Widget::bounds()*/
    sf::FloatRect bounds() const override;

    /**@copydoc Widget::type()*/
    Widget::WidgetType type() const override;

    /**@copydoc Widget::update()*/
    void update(const float deltaTime) override{};

    /**@copydoc Widget::checkCollision()*/
    bool checkCollision(Widget& other) override;

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::RectangleShape mInputRect;  ///< White rectangle which represents the input area of the player.
    sf::Vector2f       mDefaultSize;
};

#endif  // BREAKOUT_WRITEABLETEXTBOX_HPP
