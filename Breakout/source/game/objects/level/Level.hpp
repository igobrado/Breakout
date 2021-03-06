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

using BrickDefinitions = std::vector<gui::BrickDef>;

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
          std::function<void(int)> scoreIncreaseCallback,
          sf::Vector2f             scalingFactor);

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

    /**
     * @brief Restarts level and creates new bricks.
     *
     * @note Call this method only and only if level is over,
     * or player wants to restart game.
     *
     * @param brickDefinitions
     */
    void createLevelFromBegining(const BrickDefinitions& brickDefinitions);

protected:
    /**
     * @brief Calls sequentially createRow() method.
     *
     * @param brickDefinitions
     */
    void createGrid(const BrickDefinitions& brickDefinitions);

    /**
     * @brief Constructs bricks in a row.
     *
     * @param row index
     * @param brickDefinitions brick mLevelBrickDefinitions
     */
    void createRow(const uint8_t& row, const BrickDefinitions& brickDefinitions);

private:
    ResourceHolder& mResourceHolder;  ///< Reference to the resource holder, where all resources are located.
                                      ///< ( Fonts, Textures, Sound)
    std::vector<gui::Brick> mBricks;  ///< Array of bricks that appear on the screen.
    gui::Ball               mBall;    ///< Ball object that appear on the screen.
    gui::Paddle             mPaddle;  ///< Paddle object that appear on the screen.

    std::function<void()> mEndLevelCallback;  ///< Callback that ends the level, callback is provided by object which
                                              ///< creates the level object

    std::function<void(int)> mScoreIncreaseCallback;  ///< Functor that shall receive number
                                                      ///< for how much score should increase.
    const sf::Vector2f   mScalingFactor;              ///< Scaling factor that is being used to scale the textures.
    static constexpr int sIncreaseWHenBrickIsWeaken    = 1;  ///< To avoid magic numbers in codebase.
    static constexpr int sIncreaseWhenBrickIsDestroyed = 2;
};

#endif  // BREAKOUT_LEVEL_HPP
