cmake_minimum_required(VERSION 3.17)
project(simple_ps1_games C)

set(CMAKE_C_STANDARD 11)

include_directories(src)
include_directories(src/games)

add_executable(simple_ps1_games
        src/games/tic_tac_toe_game.c
        src/games/tic_tac_toe_game.h
        src/controller.c
        src/controller.h
        src/core.c
        src/core.h
        src/engine.c
        src/engine.h
        src/main.c
        src/screen_selector.c
        src/screen_selector.h)
