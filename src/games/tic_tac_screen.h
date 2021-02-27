#ifndef SIMPLE_PS1_GAMES_TIC_TAC_SCREEN_H
#define SIMPLE_PS1_GAMES_TIC_TAC_SCREEN_H

#include "tic_tac_toe_game.h"


#define PL1_SPRITE 0
#define PL2_SPRITE 1
#define PL1_SEL_SPRITE 2
#define PL2_SEL_SPRITE 3
#define BACK_SPRITE_1 4
#define BACK_SPRITE_2 5
#define LOGO_TIC_SPRITE 6


int curSelectedMenu;
int isLockUpdate;
int indexFor;
int waitStartTicTac;

void drawTicTacScreen();
void updateTicTacScreen();
void initTicTacScreen();
void freeSprites();
#endif //SIMPLE_PS1_GAMES_TIC_TAC_SCREEN_H
