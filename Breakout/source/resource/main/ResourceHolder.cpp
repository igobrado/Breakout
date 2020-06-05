#include "ResourceHolder.hpp"

ResourceHolder::ResourceHolder()
    : mTextureManager{"../resource/xml/Textures.xml"}
    , mSoundManager{"../resource/xml/Sound.xml"}
{

}

const sf::Texture& ResourceHolder::getTexture(std::string_view targetID) const
{
    return mTextureManager.getProperty(targetID);
}

void ResourceHolder::play(std::string_view music)
{
    mSoundManager.play(music);
}