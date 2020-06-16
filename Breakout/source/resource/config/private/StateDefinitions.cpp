#include "StateDefinitions.hpp"

#include "Textbox.hpp"
#include "WriteableTextbox.hpp"

std::vector<std::unique_ptr<Widget>>
        StateDefinitions::getWidgets(const char* xmlFilePath, sf::Font& font, const char* stateName)
{
    std::vector<std::unique_ptr<Widget>> widgets{};
    tinyxml2::XMLDocument                document;
    if (document.LoadFile(xmlFilePath) == tinyxml2::XML_SUCCESS)
    {
        auto startPos{ document.FirstChildElement("Config") };
        auto element{ startPos->FirstChildElement(stateName)->FirstChildElement("Textbox") };

        for (;  //
             element;
             element = element->NextSiblingElement(("Textbox")))
        {
            const char*   text      = "";
            const char*   color     = "";
            std::uint64_t writeable = 0U;
            std::uint64_t coordX    = 0U;
            std::uint64_t coordY    = 0U;
            std::uint64_t size      = 0U;

            element->QueryStringAttribute("Text", &text);
            element->QueryUnsigned64Attribute("PosX", &coordX);
            element->QueryUnsigned64Attribute("PosY", &coordY);
            element->QueryUnsigned64Attribute("Writeable", &writeable);
            element->QueryUnsigned64Attribute("Size", &size);
            element->QueryStringAttribute("Color", &color);

            if (writeable)
            {
                widgets.push_back(
                        std::make_unique<WriteableTextbox>(coordX, coordY, font, stringToSFMLColor(color), text));
            }
            else
            {
                widgets.push_back(std::make_unique<Textbox>(coordX, coordY, font, stringToSFMLColor(color), text));
            }
        }
    }
    return std::move(widgets);
}
sf::Color StateDefinitions::stringToSFMLColor(const std::string& color)
{
    if (color == "Black")
        return sf::Color::Black;
    else if (color == "White")
        return sf::Color::White;
    else if (color == "Red")
        return sf::Color::Red;
    else if (color == "Green")
        return sf::Color::Green;
    else if (color == "Yellow")
        return sf::Color::Yellow;
    else if (color == "Magenta")
        return sf::Color::Magenta;
    else if (color == "Cyan")
        return sf::Color::Cyan;
    else if (color == "Transparent")
        return sf::Color::Transparent;
    else
        return sf::Color::Blue;
}
