#include "ResourceHolder.hpp"

ResourceHolder::ResourceHolder()
    : mTextureManager{"../resource/xml/Textures.xml"}
    , mSoundManager{""}
{

}

const sf::Texture& ResourceHolder::getTexture(std::string_view targetID) const
{
    return mTextureManager.getProperty(targetID);
}
