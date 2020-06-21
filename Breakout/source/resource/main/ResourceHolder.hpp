#ifndef BREAKOUT_RESOURCEHOLDER_HPP
#define BREAKOUT_RESOURCEHOLDER_HPP
#include <SFML/Graphics.hpp>

#include "../managers/Manager.hpp"
#include "Config.hpp"
#include "Scoreboard.hpp"

/**
 * @brief Holds instances of Managers related objects.
 *
 * True the managers related objects, data like textures,
 * sound etc. Can be accessed.
 */
class ResourceHolder
{
public:
    ResourceHolder(
            const sf::RenderWindow&                             renderWindow,
            const std::map<std::string, std::function<void()>>& introStateSwitchesCallbackMap,
            const std::function<void(const Player& player)>&    inputStateSwitchesCallback);

    /**
     * @return Valid reference to texture object
     * @throws std::out_of_range if there is no mapped texture.
     */
    sf::Texture& getTexture(const std::string_view targetID);
    sf::Font&    getFont(const std::string_view targetID);

    /**
     * @brief Returns reference to config with provided targetID.
     *
     * @param targetID ID of wanted config. ( Currently <b>INTRO AND INPUT</b>
     * @return Reference to config, reference is guaranteed to be valid until ResourceHolder object is destroyed.
     */
    Config& getConfig(std::string_view targetID);

    /**
     * @brief Plays sound with targetID.
     *
     * @param sound name of sound.
     */
    void play(std::string_view sound);

private:
    FontManager    mFontManager;
    TextureManager mTextureManager;
    SoundManager   mSoundManager;

    std::map<std::string, std::unique_ptr<Config>, defined::str_less> mConfigs;
};

#endif  // BREAKOUT_RESOURCEHOLDER_HPP
