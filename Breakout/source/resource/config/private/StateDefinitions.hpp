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

    [[nodiscard]] std::vector<std::unique_ptr<Widget>>&& getWidgets(const char* xmlFilePath, sf::Font& font) const;

private:
    StateDefinitions() = default;
};

#endif  // BREAKOUT_STATEDEFINITIONS_HPP
