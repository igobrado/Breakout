#ifndef BREAKOUT_MANAGER_HPP
#define BREAKOUT_MANAGER_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstring>
#include <thread>
#include <atomic>
#include <iostream>
#include <map>
#include <memory>
#include <fstream>

#include "Template.hpp"
#include "tinyxml2.h"

/**
 * @brief Generic manager representation.
 *
 * @note Every manager-like class shall inherit from it.
 * @tparam T
 */

template <typename T>
class Manager
{
public:
    Manager()  //
        : mDocument{}
        , mData{}
    {
    }

public:
    /**
     * @brief Looks for object inside of map with targetID.
     *
     * @param targetID id of target object.
     * @return founded object.
     * @throws std::out_of_range if object was not found.
     */
    T& getProperty(const std::string_view targetID)
    {
        auto found = mData.find(targetID);
        if (found == std::end(mData))
        {
            throw std::out_of_range("No data in map with key: " + std::string{ targetID } + "\n");
        }
        return found->second;
    }

    /**
     * @brief converts const char* to string with lower-case characters
     * @param str input string
     * @return output string
     */
    std::string tolower(const char* str)
    {
        std::string t{ str };
        std::transform(t.begin(), t.end(), t.begin(), ::tolower);
        return t;
    }

protected:
    /**
     * @brief forwards argumets to std::map<>::emplace.
     *
     * @tparam Args T value of container.
     * @param args  data to construct object.
     * @return True if insert happened.
     */
    template <typename... Args>
    auto emplace(Args&&... args)
    {
        return mData.emplace(std::forward<Args>(args)...);
    }

    /**
     * @brief Loads XML file and constructs map according to it.
     *
     * @param startPos start module of xml file.
     * @param moduleName Name of module.
     * @param componentName  Wanted component to read.
     */
    void Load(tinyxml2::XMLElement* startPos, const char* moduleName, const char* componentName) = delete;

    const std::map<std::string, T, defined::str_less>& data() const
    {
        return mData;
    }

protected:
    tinyxml2::XMLDocument mDocument;  ///< XML document that shall be opened.

private:
    std::map<std::string, T, defined::str_less> mData;  ///< Map of data compared with key string that is ordered with
                                                        ///< std::lexicographical_compare
};

/**
 * @brief Implementation of manager class for texture.
 */
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
            Load(startPos, "Backgrounds", "Background");
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
            texture.setSmooth(true);
            texture.loadFromFile(path);
            static_cast<void>(                         ///< To satisfy compiler warning for discarding return value.
                    emplace(std::piecewise_construct,  //
                            std::forward_as_tuple(this->tolower(name)),  //
                            std::forward_as_tuple(std::move(texture))));
        }
    }
};

/**
 * @brief Implementation of manager class for sound.
 */
using SoundPair = std::pair<std::unique_ptr<sf::SoundBuffer>, std::shared_ptr<sf::Sound>>;
class SoundManager : public Manager<SoundPair>
{
public:
    explicit SoundManager(const char* xmlPath)  //
        : Manager{}
        , mLoaderThread{}
        , mIsLoadingOver{ false }
    {
        if (mDocument.LoadFile(xmlPath) == tinyxml2::XMLError::XML_SUCCESS)
        {
            auto startPos{ mDocument.FirstChildElement("Sounds") };
            mLoaderThread = std::thread{ &SoundManager::Load, this, startPos, "Game", "Sound" };
        }
    }
    ~SoundManager()
    {
        if (mLoaderThread.joinable())
        {
            mLoaderThread.join();
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
                static_cast<void>(  ///< To satisfy compiler warning for discarding return value.
                        emplace(std::piecewise_construct,              //
                                std::forward_as_tuple(tolower(name)),  //
                                std::forward_as_tuple(std::move(soundBuffer), std::move(sound))));
            }
        }
        if (!data().empty())
        {
            bool expect = false;
            mIsLoadingOver.compare_exchange_strong(
                    expect,  //
                    true,
                    std::memory_order_release,
                    std::memory_order_relaxed);
        }
    }

    void play(std::string_view music)
    {
        if (mIsLoadingOver.load())
        {
            try
            {
                auto& it = this->getProperty(music).second;
                it->play();
            }
            catch (std::out_of_range& excp)
            {
                std::ofstream ostr{ "ErrorLog.txt", std::ios::out };
                ostr << "Playing music failed with: " << excp.what() << std::endl;
            }
        }
    }

private:
    std::thread      mLoaderThread;   ///< Thread in which loading of sound is being done.
    std::atomic_bool mIsLoadingOver;  ///< Atomic variable that is indicating is loading of sound over.
};

class FontManager : public Manager<sf::Font>
{
public:
    explicit FontManager(const char* xmlFile)  //
        : Manager{}
    {
        if (mDocument.LoadFile(xmlFile) == tinyxml2::XML_SUCCESS)
        {
            auto startPos{ mDocument.FirstChildElement("Fonts") };
            Load(startPos, "Classic", "FontID");
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
            element->QueryStringAttribute("Font", &path);
            element->QueryStringAttribute("Name", &name);
            sf::Font font;
            if (font.loadFromFile(path))
            {
                // lot of crap here
                static_cast<void>(
                        emplace(std::piecewise_construct,
                                std::forward_as_tuple(tolower(name)),
                                std::forward_as_tuple(font)));
            }
        }
    }
};

#endif  // BREAKOUT_MANAGER_HPP
