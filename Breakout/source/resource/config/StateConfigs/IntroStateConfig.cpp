#include "IntroStateConfig.hpp"

#include "private/Arrow.hpp"
#include "private/Textbox.hpp"

IntroStateConfig::IntroStateConfig(
        const char*                                         xmlPath,
        sf::Font&                                           fontRef,
        sf::Texture&                                        arrowTexture,
        const sf::RenderWindow&                             windowRef,
        const std::map<std::string, std::function<void()>>& introStateSwitchesCallbackMap)  //
    : Config{}
    , mXmlDocumentPath{ xmlPath }
    , mFontRef{ fontRef }
    , mWidgets{ StateDefinitions::instance().getWidgets(mXmlDocumentPath, mFontRef, "Intro") }
    , mArrow{ std::make_unique<Arrow>(arrowTexture, windowRef) }
    , mSwitchStateCallbackMap{ introStateSwitchesCallbackMap }
{
}

void IntroStateConfig::drawAllComponents(sf::RenderWindow& window)
{
    std::for_each(mWidgets.begin(), mWidgets.end(), [&window](std::unique_ptr<Widget>& widget) {
        widget->draw(window);
    });
    mArrow->draw(window);
}
void IntroStateConfig::updateMovableComponents(const float deltaTime)
{
    mArrow->update(deltaTime);
    std::for_each(
            mWidgets.begin(),
            mWidgets.end(),
            [this](std::unique_ptr<Widget>& widget)  //
            {                                        //
                if (widget->checkCollision(*mArrow) && widget->type() == Widget::WidgetType::TEXTBOX)
                {
                    widget->onFocus();
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    {
                        auto it = mSwitchStateCallbackMap.find(widget->widgetsFullName());
                        if (it != mSwitchStateCallbackMap.end())
                        {
                            it->second();
                        }
                    }
                }
                else
                {
                    widget->onFocusEnded();
                }
            });
}
