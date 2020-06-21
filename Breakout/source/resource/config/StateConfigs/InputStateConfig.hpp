#ifndef BREAKOUT_INTROCONFIG_HPP
#define BREAKOUT_INTROCONFIG_HPP

#include <Config.hpp>
#include <functional>

#include "Scoreboard.hpp"
#include "Widget.hpp"
#include "private/StateDefinitions.hpp"

/**
 * @brief Represents configuration for input state.
 *
 * If there is no config in provided xmlPath level state won't terminate.
 * It shall continue working, but without features like, textboxes (if any).
 */
class InputStateConfig : public Config
{
public:
    InputStateConfig(
            const char*                                      xmlPath,
            sf::Font&                                        fontRef,
            sf::Texture&                                     arrowTexture,
            const sf::RenderWindow&                          windowRef,
            const std::function<void(const Player& player)>& inputStateSwitchesCallback);

    /**@copydoc Config::drawAllComponents()*/
    void drawAllComponents(sf::RenderWindow& window) override;

    /**@copydoc Config::updateMovableComponents()*/
    void updateMovableComponents(const float deltaTime) override;

    /**
     * @brief Handles input events.
     *
     * @param event to be handled.
     */
    void handleInput(sf::Event& event);

private:
    const char*                          mXmlDocumentPath;
    sf::Font&                            mFontRef;
    std::vector<std::unique_ptr<Widget>> mWidgets;
    std::unique_ptr<Widget>              mArrow;
    sf::String                           mPlayerInput;
    bool                                 mWidgetIsFocused;

    std::vector<std::unique_ptr<Widget>>::iterator   mFocusedTextboxIterator;
    const std::function<void(const Player& player)>& mInputStateSwitchesCallback;

    static constexpr std::uint8_t sTextMaxSize = 13U;
};

#endif  // BREAKOUT_INTROCONFIG_HPP