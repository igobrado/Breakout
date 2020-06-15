include_directories(${CMAKE_CURRENT_LIST_DIR}/main)
include_directories(${CMAKE_CURRENT_LIST_DIR}/config)
include_directories(${CMAKE_CURRENT_LIST_DIR}/input)
list(APPEND BREAKOUT_HEADERS
        ${CMAKE_CURRENT_LIST_DIR}/config/Widget.hpp
        ${CMAKE_CURRENT_LIST_DIR}/config/Config.hpp
        ${CMAKE_CURRENT_LIST_DIR}/config/StateConfigs/IntroStateConfig.hpp
        ${CMAKE_CURRENT_LIST_DIR}/config/StateConfigs/InputStateConfig.hpp
        ${CMAKE_CURRENT_LIST_DIR}/config/private/Arrow.hpp
        ${CMAKE_CURRENT_LIST_DIR}/config/private/StateDefinitions.hpp
        ${CMAKE_CURRENT_LIST_DIR}/config/private/Textbox.hpp
        ${CMAKE_CURRENT_LIST_DIR}/main/ResourceHolder.hpp
        ${CMAKE_CURRENT_LIST_DIR}/managers/Manager.hpp

        )

list(APPEND BREAKOUT_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/config/StateConfigs/IntroStateConfig.cpp
        ${CMAKE_CURRENT_LIST_DIR}/config/StateConfigs/InputStateConfig.cpp
        ${CMAKE_CURRENT_LIST_DIR}/config/private/Arrow.cpp
        ${CMAKE_CURRENT_LIST_DIR}/config/private/StateDefinitions.cpp
        ${CMAKE_CURRENT_LIST_DIR}/config/private/Textbox.cpp
        ${CMAKE_CURRENT_LIST_DIR}/main/ResourceHolder.cpp

        )

