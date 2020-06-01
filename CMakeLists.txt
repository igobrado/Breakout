cmake_minimum_required(VERSION 3.10)
project(Breakout)

set(CMAKE_CXX_STANDARD 20)
if (UNIX)
    set(SFML_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML/linux/include")
    set(SFML_LIBRARY_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML/linux/lib")
    set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/SFML/linux/lib/cmake/SFML")
endif()

if (WIN32)
    #TODO
endif()

    link_directories(SFML_LIBRARY_DIR)
    include_directories(SFML_INCLUDE_DIR)
    find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    add_executable(Breakout main.cpp)
    target_link_libraries (Breakout sfml-graphics sfml-window sfml-system sfml-audio)
endif()

