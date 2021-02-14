#ifndef SIMPLE_PS1_GAMES_TIC_TAC_SCREEN_H
#define SIMPLE_PS1_GAMES_TIC_TAC_SCREEN_H

#include "../engine.h"
#include "../controller.h"
#include "../core.h"

u_long *dataTimScreen[7];

GsSPRITE *pl1Sprite;
GsSPRITE *pl1SelectedSprite;
GsSPRITE *pl2Sprite;
GsSPRITE *pl2SelectedSprite;
GsSPRITE *backSprite1;
GsSPRITE *backSprite2;
GsSPRITE *logoTicSprite;

Sprite *sprites[7];

int curSelectedMenu;
int isLockUpdate;
int indexFor;
int waitStartTicTac;

void drawTicTacScreen();
void updateTicTacScreen();
void initTicTacScreen();
void freeSprites();
#endif //SIMPLE_PS1_GAMES_TIC_TAC_SCREEN_H
