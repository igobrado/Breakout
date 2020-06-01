#ifndef BREAKOUT_LEVEL_HPP
#define BREAKOUT_LEVEL_HPP

#include <unordered_map>
#include <vector>

#include <SFML/Graphics.hpp>

enum class LevelID
{
    FIRST,
    SECOND,
    THIRD
};

struct BrickPrefix
{
    // obj::BrickColor color;
    int strength;
};
using BrickDefinitions = std::vector<BrickPrefix>;
// using BrickDefinitionMap = std::unordered_map<lvl::LevelID, BrickDefinitions>;

class Level
{
public:
    Level();
    ~Level();

    Level& operator=(Level&& other);
    void   Update(const float& deltaTime);
    void   Draw(sf::RenderWindow& window);
    bool   LoadLevel();

protected:
    void CreateRow(const uint8_t& row);
    // std::vector<obj::Brick>::iterator CheckBrickCollision();
    BrickDefinitions::const_iterator BrickDefinition(const int& brickIndex);
};

#endif  // BREAKOUT_LEVEL_HPP
