#ifndef BREAKOUT_INTROSTATECONFIG_HPP
#define BREAKOUT_INTROSTATECONFIG_HPP

#include <Config.hpp>
#include <functional>

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
    IntroStateConfig(
            const char*                                         xmlPath,
            sf::Font&                                           fontRef,
            sf::Texture&                                        arrowTexture,
            const sf::RenderWindow&                             windowRef,
            const std::map<std::string, std::function<void()>>& introStateSwitchesCallbackMap);

    /**@copydoc Config::drawAllComponents()*/
    void drawAllComponents(sf::RenderWindow& window) override;

    /**@copydoc Config::updateMovableComponents()*/
    void updateMovableComponents(const float deltaTime) override;

private:
    const char* mXmlDocumentPath;  ///< Path to xml file.
    sf::Font&   mFontRef;          ///< Ref provided by object who construct this one,
                                   ///< used for constructing widget objects.

    std::vector<std::unique_ptr<Widget>> mWidgets;  ///< Array of widgets that this config file has.
    std::unique_ptr<Widget>              mArrow;    ///< Arrow for this config file.

    /**
     * Used to hold lambda functions.
     * Describes possible state changes from intro to --. Shall be pass as const ref to IntroStateConfig object.
     */
    const std::map<std::string, std::function<void()>>& mSwitchStateCallbackMap;
};

#endif  // BREAKOUT_INTROSTATECONFIG_HPP