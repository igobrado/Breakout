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
#include "states/ScoreboardState.hpp"

class StateFactory
{
public:
    /**
     * @brief Creates the fresh unique ptr of state.
     *
     * @param stateType Which state shall be created.
     * @param data shared gamedata between states.
     *
     *
     * @return std::make_unique<machine::IntroState> if machine::StateType::INTRO is provided as stateType
     * @return std::make_unique<machine::MenuState> if machine::StateType::MENU is provided as stateType
     * @return std::make_unique<machine::GameState> if machine::StateType::GAME is provided as stateType
     * @return std::make_unique<machine::EndState> if machine::StateType::END is provided as stateType
     * @return std::make_unique<machine::InputState> if machine::StateType::INPUT is provided as stateType
     * @return std::make_unique<machine::ScoreboardState> if machine::StateType::SCOREBOARD is provided as stateType
     *
     * @return nullptr stateType didn't appear in StateType enum.
     */
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
            case machine::StateType::SCOREBOARD:
                return std::make_unique<machine::ScoreboardState>(data);
            default:
                return nullptr;
        }
    }
};

#endif  // BREAKOUT_STATEFACTORY_HP
