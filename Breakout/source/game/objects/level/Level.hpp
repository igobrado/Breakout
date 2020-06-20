#ifndef BREAKOUT_LEVEL_HPP
#define BREAKOUT_LEVEL_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <unordered_map>
#include <vector>

#include "Ball.hpp"
#include "Brick.hpp"
#include "Paddle.hpp"
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
 * Level objects with different mLevelBrickDefinitions shall construct from this class.
 */
class Level
{
public:
    Level(ResourceHolder&          resourceHolder,
          const BrickDefinitions&  brickDefinitions,
          std::function<void()>    endLevelCallback,
          std::function<void(int)> scoreIncreaseCallback);

    /**
     * @brief Updates the scene.
     *
     * Calls update method from movable objects.
     * @param deltaTime
     *
     * @return true if level should end.
     */
    bool update(const float& deltaTime);

    /**
     * @brief draws scene to screen.
     *
     * @note Calls draw method from drawable objects.
     * @param window to draw onto.
     */
    void draw(sf::RenderWindow& window);

    void createLevelFromBegining(const BrickDefinitions& brickDefinitions);

protected:
    /**
     * @brief Constructs bricks in a row.
     *
     * @param row index
     * @param brickDefinitions brick mLevelBrickDefinitions
     */
    void createRow(const uint8_t& row, const BrickDefinitions& brickDefinitions);

    void createGrid(const BrickDefinitions& brickDefinitions);

private:
    ResourceHolder&          mResourceHolder;
    std::vector<gui::Brick>  mBricks;
    gui::Ball                mBall;
    gui::Paddle              mPaddle;
    std::function<void()>    mEndLevelCallback;
    std::function<void(int)> mScoreIncreaseCallback;  ///< Functor that shall receive number
                                                      ///< for how much score should increase.

    static constexpr int sIncreaseWHenBrickIsWeaken    = 1;  ///< To avoid magic numbers in codebase.
    static constexpr int sIncreaseWhenBrickIsDestroyed = 2;

};

#endif  // BREAKOUT_LEVEL_HPP
