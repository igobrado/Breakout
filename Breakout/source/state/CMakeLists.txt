include_directories("${CMAKE_CURRENT_LIST_DIR}/interface")
include_directories("${CMAKE_CURRENT_LIST_DIR}/source")

list(APPEND BREAKOUT_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/source/states/EndState.cpp
        ${CMAKE_CURRENT_LIST_DIR}/source/states/GameState.cpp
        ${CMAKE_CURRENT_LIST_DIR}/source/states/IntroState.cpp
        ${CMAKE_CURRENT_LIST_DIR}/source/states/MenuState.cpp
        ${CMAKE_CURRENT_LIST_DIR}/source/StateMachine.cpp

        )

list(APPEND BREAKOUT_HEADERS
        ${CMAKE_CURRENT_LIST_DIR}/interface/State.hpp
        ${CMAKE_CURRENT_LIST_DIR}/interface/StateMachine.hpp
        ${CMAKE_CURRENT_LIST_DIR}/source/states/EndState.hpp
        ${CMAKE_CURRENT_LIST_DIR}/source/states/GameState.hpp
        ${CMAKE_CURRENT_LIST_DIR}/source/states/IntroState.hpp
        ${CMAKE_CURRENT_LIST_DIR}/source/states/MenuState.hpp
        )
