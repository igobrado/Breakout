set(COMMON_DIR "${CMAKE_CURRENT_LIST_DIR}/common")
set(INTERFACE_DIR "${CMAKE_CURRENT_LIST_DIR}/objects/interface")

include_directories("${COMMON_DIR}")

list(APPEND BREAKOUT_SOURCES
        ${COMMON_DIR}/GameData.cpp
        )

list(APPEND BREAKOUT_HEADERS
        ${COMMON_DIR}/GameData.hpp
        ${INTERFACE_DIR}/Moveable.hpp
        ${INTERFACE_DIR}/Drawable.hpp
        )