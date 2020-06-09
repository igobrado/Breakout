#ifndef BREAKOUT_INTROCONFIG_HPP
#define BREAKOUT_INTROCONFIG_HPP

#include <Config.hpp>

#include "Widget.hpp"
#include "private/StateDefinitions.hpp"

/**
 * @brief Represents configuration for intro state.
 *
 * If there is no config in provided xmlPath level state won't terminate.
 * It shall continue working, but without features like, textboxes (if any).
 */
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