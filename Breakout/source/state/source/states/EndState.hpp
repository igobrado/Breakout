#ifndef BREAKOUT_ENDSTATE_HPP
#define BREAKOUT_ENDSTATE_HPP

#include "State.hpp"
#include "GameData.hpp"

namespace machine
{

class EndState : public State
{
public:
    explicit EndState(::common::GameData& gameData);
    ~EndState() override;
    void update(const float deltaTime) override;
    void handleInput() override;
    void draw() override;

protected:
    void onMouseKeyPressed(const sf::Mouse::Button button);
private:
    ::common::GameData& mGameData;
};

}  // namespace machine

#endif  // BREAKOUT_ENDSTATE_HPP
