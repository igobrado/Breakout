include_directories(${CMAKE_CURRENT_LIST_DIR}/main)
list(APPEND BREAKOUT_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/main/ResourceHolder.cpp
        ${CMAKE_CURRENT_LIST_DIR}/managers/Manager.cpp
        )

list(APPEND BREAKOUT_HEADERS
        ${CMAKE_CURRENT_LIST_DIR}/main/ResourceHolder.hpp
        ${CMAKE_CURRENT_LIST_DIR}/managers/Manager.hpp
        )


include(${CMAKE_CURRENT_LIST_DI}/config/StateConfigs)
