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
            const char*   text          = "",
            std::uint64_t size          = 60);

    /**@copydoc Widget::bounds()*/
    sf::FloatRect bounds() const override;

    /**@copydoc Widget::type()*/
    Widget::WidgetType type() const override;

    /**@copydoc Drawable::draw()*/
    void draw(sf::RenderWindow& window) override;

    /**@copydoc Widget::update()*/
    void update(const float deltaTime) override{};

    /**@copydoc Widget::checkCollision()*/
    bool checkCollision(Widget& other) override;

private:
    sf::RectangleShape mInputRect;
};

#endif  // BREAKOUT_WRITEABLETEXTBOX_HPP
