#ifndef BREAKOUT_STATEDEFINITIONS_HPP
#define BREAKOUT_STATEDEFINITIONS_HPP

#include <SFML/Graphics/Font.hpp>
#include <memory>
#include <vector>

#include "Widget.hpp"
#include "tinyxml2.h"

class StateDefinitions
{
public:
    [[nodiscard]] static StateDefinitions& instance()
    {
        static StateDefinitions instance;
        return instance;
    }

    /**
     * @brief Reads the config file and returns vector of constructed widgets.
     *
     * @param xmlFilePath Path to xml file.
     * @param font to be used on widgets.
     * @param stateName Name of the state for which config is.
     *
     * @return Array of widgets found in config file.
     */
    [[nodiscard]] std::vector<std::unique_ptr<Widget>>
            getWidgets(const char* xmlFilePath, sf::Font& font, const char* stateName);

    /**
     * @brief Converts string to sfml color object.
     *
     * @note If color was not found, then Black will be returned by default.
     *
     * @param color in string.
     *
     * @return sf::Color::Black;       ///< Black predefined color.
     * @return sf::Color::White;       ///< White predefined color.
     * @return sf::Color::Red;         ///< Red predefined color.
     * @return sf::Color::Green;       ///< Green predefined color.
     * @return sf::Color::Blue;        ///< Blue predefined color.
     * @return sf::Color::Yellow;      ///< Yellow predefined color.
     * @return sf::Color::Magenta;     ///< Magenta predefined color.
     * @return sf::Color::Cyan;        ///< Cyan predefined color.
     * @return sf::Color::Transparent; ///< Transparent (black) predefined color.
     */
    static sf::Color stringToSFMLColor(const std::string& color);

private:
    StateDefinitions() = default;
};

#endif  // BREAKOUT_STATEDEFINITIONS_HPP
