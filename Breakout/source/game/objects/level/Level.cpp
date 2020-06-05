#include "Level.hpp"

#include <random>

Level::Level(
        ResourceHolder&         resourceHolder,
        const BrickDefinitions& brickDefinitions,
        std::function<void()>&& endLevelCallback)
    : mResourceHolder{ resourceHolder }
    , mBall{ mResourceHolder.getTexture("ball") }
    , mEndLevelCallback{ std::move(endLevelCallback) }
{
    for (auto i : { 1, 2, 3, 4, 5 })
    {
        createRow(i, brickDefinitions);
    }
}

Level::Level(Level&& other) noexcept
    : mResourceHolder{ other.mResourceHolder }
    , mBall{ std::move(other.mBall) }
    , mBricks{ std::move(other.mBricks) }
{
}

Level& Level::operator=(Level&& other) noexcept
{
    if (this != &other)
    {
        // mBall = std::move(other.mBall);
    }
    return *this;
}

void Level::update(const float& deltaTime)
{
    mBall.updateMovement(deltaTime);

    auto it = checkBrickCollision();
    // if (it != std::end(mBricks))
    //{
    //    mBricks.erase(it);
    //    // increaseScore
    //    if (!mBricks.size())
    //    {
    //        // kill level
    //    }
    //}
    if (mBall.definitions().currentPosition.y < 0)
    {
        // if ball is lower then paddle kill level, for now leave empty.
    }
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
}

void Level::createRow(const uint8_t& row, const BrickDefinitions& brickDefinitions)
{
    std::random_device              rd;
    std::mt19937                    gen{ rd() };
    std::uniform_int_distribution<> distrib{ 0, static_cast<int>(brickDefinitions.size() - 1) };

    for (std::uint8_t i = 0U; i != 16U; ++i)
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
            if (brick.shouldDestroy())
            {
                return true;
            }
        }
        return brick.shouldDestroy();
    });
}