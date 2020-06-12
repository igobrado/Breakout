#include "StateDefinitions.hpp"

#include "Textbox.hpp"

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
            const char*   text          = "";
            std::uint64_t writeable     = 0U;
            std::uint64_t useBackground = 0U;
            std::uint64_t coordX        = 0U;
            std::uint64_t coordY        = 0U;
            std::uint64_t size          = 0U;
            std::uint64_t hasArrow      = 0U;

            element->QueryStringAttribute("Text", &text);
            element->QueryUnsigned64Attribute("PosX", &coordX);
            element->QueryUnsigned64Attribute("PosY", &coordY);
            element->QueryUnsigned64Attribute("Writeable", &writeable);
            element->QueryUnsigned64Attribute("UseBackground", &useBackground);
            element->QueryUnsigned64Attribute("Size", &size);

            widgets.push_back(std::make_unique<Textbox>(
                    coordX,
                    coordY,
                    font,
                    text,
                    static_cast<bool>(useBackground),
                    static_cast<bool>(writeable),
                    size));
        }
    }
    return std::move(widgets);
}