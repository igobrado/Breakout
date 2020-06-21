#ifndef BREAKOUT_GAMESTATE_HPP
#define BREAKOUT_GAMESTATE_HPP

#include "GameData.hpp"
#include "LevelStack.hpp"
#include "State.hpp"
namespace machine
{

class GameState : public State
{
public:
    explicit GameState(::common::GameData& gameData);

    /**@copydoc State::update()*/
    void update(const float deltaTime) override;

    /**@copydoc State::handleInput()*/
    void handleInput() override;

    /**@copydoc State::draw()*/
    void draw() override;

private:
    ::common::GameData& mGameData;    ///< Reference to  shared game data(Resource holder etc..)
    LevelStack          mLevelStack;  ///< Levels that this game has.
    sf::Sprite          mBackground;  ///< Background of the state.

    std::vector<BrickDefinitions> mLevelBrickDefinitions;  ///< Brick Definitions for each level.
    bool                          mShouldContinue;         ///< Indicates should level continue
                                                           ///< with displaying, if false game
                                                           ///< pauses until enter is press.

    uint8_t mNumberOfLevels;  ///< Number of how many levels game has.
};

}  // namespace machine
#endif  // BREAKOUT_GAMESTATE_HPP
