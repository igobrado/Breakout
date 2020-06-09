#ifndef BREAKOUT_INTROCONFIG_HPP
#define BREAKOUT_INTROCONFIG_HPP

#include <Config.hpp>

#include "Widget.hpp"
#include "private/StateDefinitions.hpp"

class IntroStateConfig : public Config
{
public:
    IntroStateConfig(const char* xmlPath, sf::Font& fontRef);

    /**@copydoc Config::drawAllComponents()*/
    void drawAllComponents(sf::RenderWindow& window) override;

private:
    const char*                          mXmlDocumentPath;
    sf::Font&                            mFontRef;
    std::vector<std::unique_ptr<Widget>> mWidgets;
};

#endif  // BREAKOUT_INTROCONFIG_HPP