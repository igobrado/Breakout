#include "ResourceHolder.hpp"

#include "StateConfigs/IntroStateConfig.hpp"

ResourceHolder::ResourceHolder()
    : mFontManager{ "../resource/xml/Font.xml" }
    , mTextureManager{ "../resource/xml/Textures.xml" }
    , mSoundManager{ "../resource/xml/Sound.xml" }
    , mConfigs{}
{
    mConfigs["intro"] = std::make_unique<IntroStateConfig>(
            "../resource/xml/state/intro.xml",
            mFontManager.getPropertyFuture().get());
}

const sf::Texture& ResourceHolder::getTexture(std::string_view targetID) const
{
    return mTextureManager.getProperty(targetID);
}

const sf::Font& ResourceHolder::getFont(std::string_view targetID) const
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