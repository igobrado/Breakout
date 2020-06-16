include_directories("${CMAKE_CURRENT_LIST_DIR}/interface")
set(SANDBOX_DIR "${CMAKE_CURRENT_LIST_DIR}/source/app")

list(APPEND BREAKOUT_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/source/main.cpp
    ${SANDBOX_DIR}/Breakout.cpp
        )

list(APPEND BREAKOUT_HEADERS
        ${CMAKE_CURRENT_LIST_DIR}/interface/Application.hpp
        ${SANDBOX_DIR}/Breakout.hpp
        )