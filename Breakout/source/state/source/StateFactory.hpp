#ifndef BREAKOUT_STATEFACTORY_HP
#define BREAKOUT_STATEFACTORY_HP

#include <memory>

#include "GameData.hpp"
#include "State.hpp"
#include "states/EndState.hpp"
#include "states/GameState.hpp"
#include "states/InputState.hpp"
#include "states/IntroState.hpp"
#include "states/MenuState.hpp"

class StateFactory
{
public:
    static std::unique_ptr<machine::State> getState(const machine::StateType stateType, common::GameData& data)
    {
        switch (stateType)
        {
            case machine::StateType::INTRO:
                return std::make_unique<machine::IntroState>(data);
            case machine::StateType::MENU:
                return std::make_unique<machine::MenuState>(data);
            case machine::StateType::GAME:
                return std::make_unique<machine::GameState>(data);
            case machine::StateType::END:
                return std::make_unique<machine::EndState>(data);
            case machine::StateType::INPUT:
                return std::make_unique<machine::InputState>(data);
            default:
                return nullptr;
        }
    }
};

#endif  // BREAKOUT_STATEFACTORY_HP
