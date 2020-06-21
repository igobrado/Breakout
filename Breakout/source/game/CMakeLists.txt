set(COMMON_DIR "${CMAKE_CURRENT_LIST_DIR}/common")
include_directories("${COMMON_DIR}")
include_directories("${CMAKE_CURRENT_LIST_DIR}/objects/interface")
include_directories("${CMAKE_CURRENT_LIST_DIR}/objects/level")
include_directories("${CMAKE_CURRENT_LIST_DIR}/objects/source/obj")

list(APPEND BREAKOUT_SOURCES
        ${COMMON_DIR}/GameData.cpp
        ${COMMON_DIR}/Scoreboard.cpp
        ${CMAKE_CURRENT_LIST_DIR}/objects/level/Level.cpp
        ${CMAKE_CURRENT_LIST_DIR}/objects/source/obj/Brick.cpp
        ${CMAKE_CURRENT_LIST_DIR}/objects/source/obj/Ball.cpp
        ${CMAKE_CURRENT_LIST_DIR}/objects/source/obj/Paddle.cpp
        )

list(APPEND BREAKOUT_HEADERS
        ${COMMON_DIR}/GameData.hpp
        ${COMMON_DIR}/Scoreboard.hpp
        ${COMMON_DIR}/ScreenDimensions.hpp
        ${CMAKE_CURRENT_LIST_DIR}/objects/source/obj/Brick.hpp
        ${CMAKE_CURRENT_LIST_DIR}/objects/source/obj/Ball.hpp
        ${CMAKE_CURRENT_LIST_DIR}/objects/level/Level.hpp
        ${CMAKE_CURRENT_LIST_DIR}/objects/level/LevelStack.hpp
        ${CMAKE_CURRENT_LIST_DIR}/objects/source/obj/Paddle.hpp
        )