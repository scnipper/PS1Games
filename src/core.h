//
// Created by yoba2 on 26.09.2020.
//

#ifndef SIMPLE_PS1_GAMES_CORE_H
#define SIMPLE_PS1_GAMES_CORE_H
#include "engine.h"

Sprite *spritesPool[7];
u_long *dataPool[7];


int pause;
enum State {
    LOGO,SELECT_SCREEN,TIC_TAC,TIC_TAC_SCREEN
} mainState;

void (*initFuncs[4])(void);

void setState(enum State state);

#endif //SIMPLE_PS1_GAMES_CORE_H
