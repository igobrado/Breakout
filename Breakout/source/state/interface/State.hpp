#ifndef BREAKOUT_STATE_HPP
#define BREAKOUT_STATE_HPP

namespace machine
{

enum class StateType
{
    INTRO,
    MENU,
    GAME,
    END
};

class State
{
public:
    State()          = default;
    virtual ~State() = default;

    State(const State&) = delete;
    State& operator=(const State&) = delete;

    virtual void update(const float deltaTime) = 0;
    virtual void handleInput()                 = 0;
    virtual void draw()                        = 0;
    virtual void resume(){};
    virtual void pause(){};
};
}  // namespace machine

#endif  // BREAKOUT_STATE_HPP
