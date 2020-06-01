#ifndef BREAKOUT_GAMESTATE_HPP
#define BREAKOUT_GAMESTATE_HPP

#include "GameData.hpp"
#include "State.hpp"

namespace machine
{

class GameState : public State
{
public:
    explicit GameState(::common::GameData& gameData);
    ~GameState() override;
    void update(const float deltaTime) override;
    void handleInput() override;
    void draw() override;

protected:
    void onMouseKeyPressed(const sf::Mouse::Button button);
private:
    ::common::GameData& mGameData;
};

}
#endif  // BREAKOUT_GAMESTATE_HPP
