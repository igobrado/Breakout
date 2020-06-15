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
    const char*                                         mXmlDocumentPath;
    sf::Font&                                           mFontRef;
    std::vector<std::unique_ptr<Widget>>                mWidgets;
    std::unique_ptr<Widget>                             mArrow;
    const std::map<std::string, std::function<void()>>& mSwitchStateCallbackMap;
};

#endif  // BREAKOUT_INTROSTATECONFIG_HPP