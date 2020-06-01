set(COMMON_DIR "${CMAKE_CURRENT_LIST_DIR}/common")
include_directories("${COMMON_DIR}")

list(APPEND BREAKOUT_SOURCES
        ${COMMON_DIR}/GameData.cpp
        )

list(APPEND BREAKOUT_HEADERS
        ${COMMON_DIR}/GameData.hpp
        )