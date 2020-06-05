#ifndef BREAKOUT_LEVEL_HPP
#define BREAKOUT_LEVEL_HPP

#include <functional>
#include <unordered_map>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Ball.hpp"
#include "Brick.hpp"
#include "ResourceHolder.hpp"

/**
 * @brief Level typed enum.
 *
 * Represents how many levels game shall have.
 */
enum class LevelID
{
    FIRST,
    SECOND,
    THIRD
};

using BrickDefinitions    = std::vector<gui::BrickDef>;
using BrickDefinitionsMap = std::unordered_map<LevelID, BrickDefinitions>;

/**
 * @brief Represents generic level.
 *
 * Level objects with different definitions shall construct from this class.
 */
class Level
{
public:
    Level(ResourceHolder&         resourceHolder,
          const BrickDefinitions& brickDefinitions,
          std::function<void()>&& endLevelCallback);
    Level(Level&& other) noexcept;
    Level& operator=(Level&& other) noexcept;
    /**
     * @brief Updates the scene.
     *
     * Calls update method from movable objects.
     * @param deltaTime
     */
    void update(const float& deltaTime);

    /**
     * @brief draws scene to screen.
     *
     * @note Calls draw method from drawable objects.
     * @param window to draw onto.
     */
    void draw(sf::RenderWindow& window);

protected:
    /**
     * @brief Constructs bricks in a row.
     *
     * @param row index
     * @param brickDefinitions brick definitions
     */
    void createRow(const uint8_t& row, const BrickDefinitions& brickDefinitions);

    /**
     * @brief Checks collision between ball and brick.
     *
     * @return it to collided brick, if collision happen, if not std::end(std::vector<>)
     */
    std::vector<gui::Brick>::iterator checkBrickCollision();

private:
    ResourceHolder&         mResourceHolder;
    std::vector<gui::Brick> mBricks;
    gui::Ball               mBall;
    std::function<void()>   mEndLevelCallback;
};

#endif  // BREAKOUT_LEVEL_HPP
