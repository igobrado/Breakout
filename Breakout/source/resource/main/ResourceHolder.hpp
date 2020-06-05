#ifndef BREAKOUT_RESOURCEHOLDER_HPP
#define BREAKOUT_RESOURCEHOLDER_HPP
#include <SFML/Graphics.hpp>

#include "../managers/Manager.hpp"

/**
 * @brief Holds instances of Managers related objects.
 *
 * True the managers related objects, data like textures,
 * sound etc. Can be accessed.
 */
class ResourceHolder
{
public:
    ResourceHolder();

    /**
     * @return Valid reference to texture object
     * @throws std::out_of_range if there is no mapped texture.
     */
    const sf::Texture& getTexture(std::string_view) const;

    void play(std::string_view music);
private:
    TextureManager mTextureManager;
    SoundManager   mSoundManager;
};

#endif  // BREAKOUT_RESOURCEHOLDER_HPP
