#ifndef BREAKOUT_RESOURCEHOLDER_HPP
#define BREAKOUT_RESOURCEHOLDER_HPP
#include <SFML/Graphics.hpp>

#include "../managers/Manager.hpp"

class ResourceHolder
{
public:
    ResourceHolder();
    const sf::Texture& getTexture(std::string_view) const;

private:
    TextureManager mTextureManager;
    SoundManager   mSoundManager;
};

#endif  // BREAKOUT_RESOURCEHOLDER_HPP
