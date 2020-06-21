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
    const char* mXmlDocumentPath;                   ///< Path to the xml document.
    sf::Font&   mFontRef;                           ///< Ref provided by object who construct this one,
                                                    ///< used for constructing widget objects.
    std::vector<std::unique_ptr<Widget>> mWidgets;  ///< Array of widgets that this config file has.
    std::unique_ptr<Widget>              mArrow;    ///< Arrow for this config file.

    sf::String mPlayerInput;      ///< Current player input that shall be displayed to the scrern.
    bool       mWidgetIsFocused;  ///< Says has player clicked on the widget,
                                  ///< if not then you can't put text any of textboxes.

    std::vector<std::unique_ptr<Widget>>::iterator mFocusedTextboxIterator;  ///< Represents currently
                                                                             ///< focused textbox iterator.

    /**
     * Lambda function.
     * Describes possible state change from input to --. Shall be pass as const ref to InputStateConfig object.
     */
    const std::function<void(const Player& player)>& mInputStateSwitchesCallback;

    static constexpr std::uint8_t sTextMaxSize = 13U;  ///< Describes how many letters can name have.
};

#endif  // BREAKOUT_INTROCONFIG_HPP