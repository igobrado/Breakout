include_directories("${CMAKE_CURRENT_LIST_DIR}/interface")

list(APPEND BREAKOUT_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/source/main.cpp)

list(APPEND BREAKOUT_HEADERS
        ${CMAKE_CURRENT_LIST_DIR}/interface/Application.hpp)