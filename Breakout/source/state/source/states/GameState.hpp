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
    ::common::GameData& mGameData;
    LevelStack          mLevelStack;
    sf::Sprite          mBackground;

    std::vector<BrickDefinitions> mLevelBrickDefinitions;
    bool                          mShouldContinue;
    uint8_t                       mNumberOfLevels;
};

}  // namespace machine
#endif  // BREAKOUT_GAMESTATE_HPP
