#ifndef BREAKOUT_WIDGET_HPP
#define BREAKOUT_WIDGET_HPP

#include <SFML/Graphics.hpp>

class Widget : public sf::Drawable
{
public:
    /**
     * @brief Every widget shall contain this datatype.
     * It's necessary to differentiate widget type.
     */
    enum class WidgetType : uint8_t
    {
        TEXTBOX = 0U,
        ARROW
    };

    ~Widget() override = default;

    /**
     * @return Widgets full name which is provided from configuration file.
     */
    [[nodiscard]] virtual std::string widgetsFullName() = 0;

    /**
     * @return global bounds of current widget.
     */
    [[nodiscard]] virtual sf::FloatRect bounds() const = 0;

    /**
     * @return widget type, Type of widget on which this method is called.
     */
    [[nodiscard]] virtual WidgetType type() const = 0;

    /**
     * @brief Updates widget current state.
     *
     * I.e. Movable widgets shall update movement,
     * widgets like textbox shall update it's content. ( if you can write on them )
     *
     * @param deltaTime
     */
    virtual void update(const float deltaTime) = 0;

    /**
     * @brief Describes what to do when cursor is on widget.
     *
     * @note Only non movable widgets shall override this method.
     */
    virtual void onFocus(){};

    /**
     * @brief Describes what to do when cursor is not on widget.
     *
     * @note Only non movable widgets shall override this method.
     */
    virtual void onFocusEnded(){};

    /**
     * @brief Checks whether widget is collided with other widget.
     *
     * @param other Widget that has been assumed for colliding.
     * @return true if collision happened, false if not.
     */
    virtual bool checkCollision(Widget& other) = 0;

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
#endif  // BREAKOUT_WIDGET_HPP
