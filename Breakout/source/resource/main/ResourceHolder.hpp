#ifndef BREAKOUT_RESOURCEHOLDER_HPP
#define BREAKOUT_RESOURCEHOLDER_HPP
#include <SFML/Graphics.hpp>

#include "../managers/Manager.hpp"
#include "Config.hpp"

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
    const sf::Texture& getTexture(std::string_view targetID) const;
    const sf::Font&    getFont(std::string_view targetID) const;

    Config& getConfig(std::string_view targetID);
    void play(std::string_view music);

private:
    FontManager    mFontManager;
    TextureManager mTextureManager;
    SoundManager   mSoundManager;

    std::map<std::string, std::unique_ptr<Config>, defined::str_less> mConfigs;
};

#endif  // BREAKOUT_RESOURCEHOLDER_HPP
