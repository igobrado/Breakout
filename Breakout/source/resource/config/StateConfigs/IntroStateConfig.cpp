#include "IntroStateConfig.hpp"

IntroStateConfig::IntroStateConfig(const char* xmlPath, sf::Font& fontRef)  //
    : Config{}
    , mXmlDocumentPath{ xmlPath }
    , mFontRef{ fontRef }
    , mWidgets{ StateDefinitions::instance().getWidgets(mXmlDocumentPath, mFontRef) }
{
}

void IntroStateConfig::drawAllComponents(sf::RenderWindow& window)
{
    std::for_each(mWidgets.begin(), mWidgets.end(), [&window](auto& widget) { widget->draw(window); });
}
