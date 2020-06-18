#include "Level.hpp"

#include <random>
#include <utility>

Level::Level(
        ResourceHolder&          resourceHolder,
        const BrickDefinitions&  brickDefinitions,
        std::function<void()>    endLevelCallback,
        std::function<void(int)> scoreIncreaseCallback)
    : mResourceHolder{ resourceHolder }
    , mBall{ mResourceHolder.getTexture("ball"), brickDefinitions[0].scalingFactor }  ///< ugly workaround
                                                                                      ///< shall be removed
    , mPaddle{ mResourceHolder.getTexture("paddle"), brickDefinitions[0].scalingFactor }
    , mEndLevelCallback{ std::move(endLevelCallback) }
    , mScoreIncreaseCallback{ std::move(scoreIncreaseCallback) }
{
    createGrid(brickDefinitions);
}

Level::Level(Level&& other) noexcept
    : mResourceHolder{ other.mResourceHolder }
    , mBall{ std::move(other.mBall) }
    , mBricks{ std::move(other.mBricks) }
    , mPaddle({ std::move(other.mPaddle) })
    , mEndLevelCallback{ std::move(other.mEndLevelCallback) }
    , mScoreIncreaseCallback{ std::move(other.mScoreIncreaseCallback) }
{
}

Level& Level::operator=(Level&& other) noexcept
{
    if (this != &other)
    {
        mBall   = std::move(other.mBall);
        mBricks = std::move(other.mBricks);
        mPaddle = std::move(other.mPaddle);
    }
    return *this;
}

bool Level::update(const float& deltaTime)
{
    mBall.updateMovement(deltaTime);
    if (mBall.isCollided(mPaddle.definitions().globalBounds))
    {
        mBall.onPaddleHit();
    }

    auto it = checkBrickCollision();
    mPaddle.updateMovement(deltaTime);
    if (it != std::end(mBricks))
    {
        mBricks.erase(it);

        if (mBricks.empty())
        {
            return true;
        }
    }

    if (mBall.definitions().currentPosition.y > mPaddle.definitions().currentPosition.y)
    {
        mEndLevelCallback();
    }
    return false;
}

void Level::draw(sf::RenderWindow& window)
{
    mBall.draw(window);
    std::for_each(
            std::begin(mBricks),
            std::end(mBricks),
            [&window, this](gui::Brick& brick)  //
            {                                   //
                brick.draw(window);
            });
    mPaddle.draw(window);
}

void Level::createRow(const uint8_t& row, const BrickDefinitions& brickDefinitions)
{
    std::random_device              rd;
    std::mt19937                    gen{ rd() };
    std::uniform_int_distribution<> distrib{ 0, static_cast<int>(brickDefinitions.size() - 1) };

    for (std::uint8_t i = 0U; i != 13U; ++i)
    {
        const auto color           = static_cast<gui::BrickColor>(distrib(gen));
        auto       brickDefinition = std::find_if(
                brickDefinitions.begin(),
                brickDefinitions.end(),  //
                [&color](const gui::BrickDef& defs) { return color == defs.color; });
        if (brickDefinition != brickDefinitions.end())
        {
            gui::BrickDef defs   = *brickDefinition;
            defs.currentPosition = { static_cast<float>(i), static_cast<float>(row) };
            mBricks.emplace_back(gui::Brick{ mResourceHolder.getTexture(  //
                                                     gui::toString(brickDefinition->color)),
                                             defs });
        }
    }
}

std::vector<gui::Brick>::iterator Level::checkBrickCollision()
{
    return std::find_if(mBricks.begin(), mBricks.end(), [this](gui::Brick& brick) {
        if (mBall.isCollided(brick.definitions().globalBounds))
        {
            brick.onHit();
            mBall.onBrickHit();
            if (brick.shouldDestroy())
            {
                mScoreIncreaseCallback(sIncreaseWhenBrickIsDestroyed);
                mResourceHolder.play("hit");
                return true;
            }
            mScoreIncreaseCallback(sIncreaseWHenBrickIsWeaken);
        }
        return false;
    });
}

void Level::createLevelFromBegining(const BrickDefinitions& brickDefinitions)
{
    mBall.resetBallPosition();
    createGrid(brickDefinitions);
}

void Level::createGrid(const BrickDefinitions& brickDefinitions)
{
    for (auto i : { 1, 2, 3, 4, 5 })
    {
        createRow(i, brickDefinitions);
    }
}
