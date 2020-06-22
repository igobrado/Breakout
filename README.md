# Breakout clone crossplatform

Breakout is cross platform game which is written in c++ ( standard c++17).
# Controls
  - Movement of paddle: Left arrow, right arrow.
  - In input state, you should click first on textbox, enter your name and press enter.
  - When you are in scoreboard state, press backspace to return into intro state.
  - When you are in end game state, to exit the game press Escape, to play again press R
# Tools that have been used: 
  - C++ as programming language
  - SFML graphics library
  - Tinyxml2 as config file parser
  - XML markup language for config files
  - CMAKE
  - VIM as coding editor
  - GDB for debugging
  - Doxygen for documentation
  - clang-format, clang-tidy
  
# Features
  - Crossplatform (tested in multiple PC's if it's not working at your PC contact me igor.obrado@gmail.com or igobrado@vsite.hr)
  - Configurable textures, soundsystem. (XML FILES UNDER ./Resource/xml shall be adapted, and pictures(sound) shall be imported under ./Resource/images(sound)).
 - Multiple levels with random brick's hit points.
 - Scoring system ( scoreborad )

Breakout is an opensource project that started as school assigment for AWP(advanced windows programmig but I wanted to learn how to games for both linux and windows in same time ;).

# TODO
- Implement Menu state which will be responsible for enabling / disabling sound, changing name of player, exiting game etc..
- Postbuild command for cmake to copy resources from one path to another (or set root directory, to be decided)

### Installation and building

# LINUX
```sh
$ git clone https://github.com/igobrado/Breakout_crossplatform.git breakout/
$ cd breakout/
$ git submodule update --init
$ mkdir build
$ cd build/
$ cmake ..
$ make -j6
```
You will need to copy SO's and resource folder to your build directory 
(dll's Breakout/Dependencies/SFML/linux/bin/)
and run the executable :) 

# WINDOWS

1) Open visual studio, continue as empty project
2) Open New->Open cmake project. ( navigate to the directory )
3) Open main.cpp which is located in: Breakout/source/entry/source/main.cpp
4) Press green build button
5) You will need to copy DLL's and resource folder to your build directory 
(dll's Breakout/Dependencies/SFML/win32/bin/ resources Breakout/resource)

# CMAKE GUI WINDOWS
1) Clone repository(With submodule update)
2) Open CMAKE-GUI
3) Navigate to the root directory
4) Choose where Soulution files (*.sln) shall be located
5) Press generate, Then choose VS2019 configuration
6) Generate
7) Open project
8) Right click on Breakout project, then click "Setup as start-up project"


