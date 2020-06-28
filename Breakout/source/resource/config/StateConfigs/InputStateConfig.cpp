#include "InputStateConfig.hpp"

#include "private/Arrow.hpp"
#include "private/Textbox.hpp"

InputStateConfig::InputStateConfig(
        const char*                                      xmlPath,
        sf::Font&                                        fontRef,
        sf::Texture&                                     arrowTexture,
        const sf::RenderWindow&                          windowRef,
        const std::function<void(const Player& player)>& inputStateSwitchesCallback)  //
    : Config{}
    , mXmlDocumentPath{ xmlPath }
    , mFontRef{ fontRef }
    , mWidgets{ StateDefinitions::instance().getWidgets(mXmlDocumentPath, mFontRef, "Input") }
    , mArrow{ std::make_unique<Arrow>(arrowTexture, windowRef) }
    , mInputStateSwitchesCallback{ inputStateSwitchesCallback }
    , mFocusedTextboxIterator{}
    , mPlayerInput{ "" }
    , mWidgetIsFocused{ false }
{
}

void InputStateConfig::drawAllComponents(sf::RenderWindow& window)
{
    std::for_each(mWidgets.begin(), mWidgets.end(), [&window](std::unique_ptr<Widget>& widget) {
        window.draw(*widget);
    });
    window.draw(*mArrow);

}

void InputStateConfig::updateMovableComponents(const float deltaTime)
{
    mArrow->update(deltaTime);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        mFocusedTextboxIterator = std::find_if(
                mWidgets.begin(),
                mWidgets.end(),
                [this](std::unique_ptr<Widget>& widget)  //
                { return widget->checkCollision(*mArrow) && (widget->type() == Widget::WidgetType::TEXTBOX); });
    }
}

bool InputStateConfig::handleInput(sf::Event& event)
{
    if (mFocusedTextboxIterator != mWidgets.end())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Backspace) && (mPlayerInput.getSize()))
        {
            mPlayerInput.erase(mPlayerInput.getSize() - 1);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        {
            try
            {
                mInputStateSwitchesCallback(Player{ std::string{ mPlayerInput.begin(), mPlayerInput.end() } });
            }
            catch(const std::out_of_range& except)
            {
                throw except;
            }
        }
        else if (mPlayerInput.getSize() < sTextMaxSize)
        {
            mPlayerInput += event.text.unicode;
        }
        dynamic_cast<Textbox&>(**mFocusedTextboxIterator).setString(mPlayerInput);
    }
    return true;
}