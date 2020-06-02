cmake_minimum_required(VERSION 3.10)

project(Breakout)
set(BREAKOUT_SOURCES)
set(BREAKOUT_HEADERS)
set(CMAKE_CXX_STANDARD 20)
set(BREAKOUT_SRC_DIR "${CMAKE_CURRENT_LIST_DIR}")

if (UNIX)
    set(SFML_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/Dependencies/SFML/linux/include")
    set(SFML_LIBRARY_DIR "${CMAKE_CURRENT_LIST_DIR}/Dependencies/SFML/linux/lib")
    set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/Dependencies/SFML/linux/lib/cmake/SFML")
endif()

if (WIN32)
    set(SFML_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/Dependencies/SFML/win32/include")
    set(SFML_LIBRARY_DIR "${CMAKE_CURRENT_LIST_DIR}/Dependencies/SFML/win32/lib")
    set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/Dependencies/SFML/win32/lib/cmake/SFML")
endif()

    link_directories(SFML_LIBRARY_DIR)
    include_directories(SFML_INCLUDE_DIR)
    include_directories("${CNAKE_CURRENT_LIST_DIR}/Dependencies/tinyxml2")
    find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    include("${BREAKOUT_SRC_DIR}/Breakout/CMakeLists.txt")
    list(APPEND BREAKOUT_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/Dependencies/tinyxml2/tinyxml2.h
        )
    list(APPEND BREAKOUT_HEADERS
        ${CMAKE_CURRENT_LIST_DIR}/Dependencies/tinyxml2/tinyxml2.cpp
        )
    add_executable(Breakout ${BREAKOUT_HEADERS} ${BREAKOUT_SOURCES})
    target_link_libraries (Breakout sfml-graphics sfml-window sfml-system sfml-audio)
endif()

