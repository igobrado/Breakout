#include "ResourceHolder.hpp"

ResourceHolder::ResourceHolder()
    : mTextureManager{ "../resource/xml/Textures.xml" }
    , mSoundManager{ "../resource/xml/Sound.xml" }
    , mFontManager{ "../resource/xml/Font.xml" }
{
}

const sf::Texture& ResourceHolder::getTexture(std::string_view targetID) const
{
    return mTextureManager.getProperty(targetID);
}

const sf::Font& ResourceHolder::getFont(std::string_view targetID) const
{
    return mFontManager.getProperty(targetID);
}

void ResourceHolder::play(std::string_view music)
{
    mSoundManager.play(music);
}