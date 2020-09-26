//
// Created by yoba2 on 26.09.2020.
//

#ifndef SIMPLE_PS1_GAMES_CORE_H
#define SIMPLE_PS1_GAMES_CORE_H
#include "engine.h"

enum State {
    LOGO,SELECT_SCREEN,TIC_TAC,SNAKE
} mainState;

void (*initFuncs[4])(void);

void setState(enum State state);

#endif //SIMPLE_PS1_GAMES_CORE_H
