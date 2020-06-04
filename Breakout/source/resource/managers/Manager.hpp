#ifndef BREAKOUT_MANAGER_HPP
#define BREAKOUT_MANAGER_HPP

#include <cstring>
#include <map>
#include <memory>

#include <SFML/Audio.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Template.hpp"
#include "tinyxml2.h"

template <typename T>
class Manager
{
    friend class Manager<sf::Texture>;

public:
    Manager()  //
        : mDocument{}
        , mData{}
    {
    }

public:
    const T& getProperty(const std::string_view targetID) const
    {
        auto found = mData.find(targetID);
        if (found == std::end(mData))
        {
            throw std::out_of_range("No data in map with " + std::string{ targetID } + "\n");
        }
        return found->second;
    }
    std::string tolower(const char* str)
    {
        std::string t{str};
        std::transform(t.begin(), t.end(), t.begin(), ::tolower);
        return t;
    }
protected:
    template <typename... Args>
    bool emplace(Args&&... args)
    {
        return mData.emplace(std::forward<Args>(args)...).second;
    }

    void Load(tinyxml2::XMLElement* startPos, const char* moduleName, const char* componentName) = delete;

protected:
    tinyxml2::XMLDocument mDocument;

private:
    std::map<std::string, T, temp::str_less> mData;
};

class TextureManager : public Manager<sf::Texture>
{
public:
    explicit TextureManager(const char* xmlPath)  //
        : Manager{}
    {
        if (mDocument.LoadFile(xmlPath) == tinyxml2::XMLError::XML_SUCCESS)
        {
            auto startPos{ mDocument.FirstChildElement("Textures") };
            Load(startPos, "Bricks", "Brick");
            Load(startPos, "Paddles", "Paddle");
            Load(startPos, "Balls", "Ball");
            Load(startPos, "Gui", "Arrow");
        }
    }

protected:
    void Load(tinyxml2::XMLElement* startPos, const char* moduleName, const char* componentName)
    {
        tinyxml2::XMLElement* element{ startPos->FirstChildElement(moduleName)->FirstChildElement(componentName) };
        const char*           path = "";
        const char*           name = "";

        for (;         //
             element;  //
             element = element->NextSiblingElement(componentName))
        {
            element->QueryStringAttribute("Texture", &path);
            element->QueryStringAttribute("Name", &name);
            sf::Texture texture{};
            texture.loadFromFile(path);
            static_cast<void>(emplace(std::piecewise_construct,  //
                    std::forward_as_tuple(tolower(name)),  //
                    std::forward_as_tuple(std::move(texture))));
        }
    }
};

using SoundPair = std::pair<std::unique_ptr<sf::SoundBuffer>, std::shared_ptr<sf::Sound>>;
class SoundManager : public Manager<SoundPair>
{
public:
    explicit SoundManager(const char* xmlPath)  //
        : Manager{}
    {
        if (mDocument.LoadFile(xmlPath) == tinyxml2::XMLError::XML_SUCCESS)
        {
            auto startPos{ mDocument.FirstChildElement("Game") };
            Load(startPos, "Game", "Hit");
            Load(startPos, "Game", "Destroy");
        }
    }

    void Load(tinyxml2::XMLElement* startPos, const char* moduleName, const char* componentName)
    {
        tinyxml2::XMLElement* element{ startPos->FirstChildElement(moduleName)->FirstChildElement(componentName) };
        const char*           path = "";
        const char*           name = "";

        for (;         //
             element;  //
             element = element->NextSiblingElement(componentName))
        {
            std::unique_ptr<sf::SoundBuffer> soundBuffer{ std::make_unique<sf::SoundBuffer>() };
            element->QueryStringAttribute("Buffer", &path);
            element->QueryStringAttribute("Name", &name);

            if (soundBuffer->loadFromFile(path))
            {
                std::shared_ptr<sf::Sound> sound{ std::make_shared<sf::Sound>() };
                sound->setBuffer(*soundBuffer);
                sound->setVolume(10.0f);
                emplace(std::piecewise_construct,     //
                        std::forward_as_tuple(tolower(name)),  //
                        std::forward_as_tuple(std::move(soundBuffer), std::move(sound)));
            }
        }
    }
};
#endif  // BREAKOUT_MANAGER_HPP
