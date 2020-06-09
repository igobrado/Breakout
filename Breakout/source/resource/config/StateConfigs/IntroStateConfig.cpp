#include "IntroStateConfig.hpp"

#include "private/Textbox.hpp"

IntroStateConfig::IntroStateConfig(const char* xmlPath, sf::Font& fontRef)  //
    : Config{}
    , mXmlDocumentPath{ xmlPath }
    , mFontRef{ fontRef }
    , mWidgets{ StateDefinitions::instance().getWidgets(mXmlDocumentPath, mFontRef) }
{
    mWidgets.push_back(std::make_unique<Textbox>(100, 100, mFontRef, "TEST"));
}

void IntroStateConfig::drawAllComponents(sf::RenderWindow& window)
{
    std::for_each(mWidgets.begin(), mWidgets.end(), [&window](auto& widget) { widget->draw(window); });
}
