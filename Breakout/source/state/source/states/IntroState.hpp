#ifndef BREAKOUT_INTROSTATE_HPP
#define BREAKOUT_INTROSTATE_HPP

#include "GameData.hpp"
#include "State.hpp"

namespace machine
{

class IntroState : public State
{
public:
    explicit IntroState(::common::GameData& gameData);
    ~IntroState() override;
    void update(const float deltaTime) override;
    void handleInput() override;
    void draw() override;

protected:
    void onMouseKeyPressed(const sf::Mouse::Button button);
private:
    ::common::GameData& mGameData;
};

}  // namespace machine

#endif  // BREAKOUT_INTROSTATE_HPP
