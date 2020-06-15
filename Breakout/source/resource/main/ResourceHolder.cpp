#include "ResourceHolder.hpp"

#include <StateConfigs/InputStateConfig.hpp>
#include <StateConfigs/IntroStateConfig.hpp>

ResourceHolder::ResourceHolder(
        const sf::RenderWindow&                             renderWindow,
        const std::map<std::string, std::function<void()>>& introStateSwitchesCallbackMap,
        const std::function<void(const Player& player)>&    inputStateSwitchesCallback)
    : mFontManager{ "../resource/xml/Font.xml" }
    , mTextureManager{ "../resource/xml/Textures.xml" }
    , mSoundManager{ "../resource/xml/Sound.xml" }
    , mConfigs{}
{
    mConfigs["intro"] = std::make_unique<IntroStateConfig>(
            "../resource/xml/state/StateConfig.xml",
            mFontManager.getProperty("asrfont"),
            mTextureManager.getProperty("arrow"),
            renderWindow,
            introStateSwitchesCallbackMap);

    mConfigs["input"] = std::make_unique<InputStateConfig>(
            "../resource/xml/state/StateConfig.xml",
            mFontManager.getProperty("asrfont"),
            mTextureManager.getProperty("arrow"),
            renderWindow,
            inputStateSwitchesCallback);
}

sf::Texture& ResourceHolder::getTexture(const std::string_view targetID)
{
    return mTextureManager.getProperty(targetID);
}

sf::Font& ResourceHolder::getFont(const std::string_view targetID)
{
    return mFontManager.getProperty(targetID);
}

Config& ResourceHolder::getConfig(std::string_view targetID)
{
    auto tmp = mConfigs.find(targetID);
    if (tmp != mConfigs.end())
    {
        return *tmp->second;
    }
    throw std::out_of_range(
            "There is no config with " + std::string{ targetID.begin() } + " Look at your path for config.");
}

void ResourceHolder::play(std::string_view music)
{
    mSoundManager.play(music);
}