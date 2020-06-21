#include "Level.hpp"

#include <random>
#include <utility>

Level::Level(
        ResourceHolder&          resourceHolder,
        const BrickDefinitions&  brickDefinitions,
        std::function<void()>    endLevelCallback,
        std::function<void(int)> scoreIncreaseCallback,
        sf::Vector2f             scalingFactor)
    : mResourceHolder{ resourceHolder }
    , mBall{ mResourceHolder.getTexture("ball") }
    , mPaddle{ mResourceHolder.getTexture("paddle") }
    , mEndLevelCallback{ std::move(endLevelCallback) }
    , mScoreIncreaseCallback{ std::move(scoreIncreaseCallback) }
    , mScalingFactor{ scalingFactor }
{
    mBall.scale(mScalingFactor);
    createGrid(brickDefinitions);
}

bool Level::update(const float& deltaTime)
{
    if (mBall.isCollided(mPaddle.handlyCalculatedGlobalBounds()))
    {
        mBall.onPaddleHit();
        mResourceHolder.play("hittwo");
    }
    auto it = std::find_if(mBricks.begin(), mBricks.end(), [this](gui::Brick& brick) {
        return brick.isCollided(mBall.handlyCalculatedGlobalBounds());
    });

    if (it != mBricks.end())
    {
        mBall.onBrickHit();
        mResourceHolder.play("hit");
        if (it->shouldDestroy())
        {
            mBricks.erase(it);
            mScoreIncreaseCallback(sIncreaseWhenBrickIsDestroyed);
        }
        else
        {
            mScoreIncreaseCallback(sIncreaseWHenBrickIsWeaken);
        }

        if (mBricks.empty())
        {
            return true;
        }
    }

    if (mBall.getPosition().y > mPaddle.getPosition().y)
    {
        mEndLevelCallback();
    }

    mBall.updateMovement(deltaTime);
    mPaddle.updateMovement(deltaTime);
    return false;
}

void Level::draw(sf::RenderWindow& window)
{
    window.draw(mBall);

    for (auto& brick : mBricks)
    {
        window.draw(brick);
    }
    window.draw(mPaddle);
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
            gui::Brick brick{ mResourceHolder.getTexture(  //
                                      gui::toString(brickDefinition->color)),
                              defs };
            brick.scale(mScalingFactor);
            mBricks.push_back(brick);
        }
    }
}

void Level::createGrid(const BrickDefinitions& brickDefinitions)
{
    for (auto i : { 1, 2, 3, 4, 5 })
    {
        createRow(i, brickDefinitions);
    }
}

void Level::createLevelFromBegining(const BrickDefinitions& brickDefinitions)
{
    mBall.resetBallPosition();
    createGrid(brickDefinitions);
}
