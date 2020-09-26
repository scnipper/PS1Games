
#ifndef SIMPLE_PS1_GAMES_TIC_TAC_TOE_GAME_H
#define SIMPLE_PS1_GAMES_TIC_TAC_TOE_GAME_H
#include "../engine.h"
#include "../controller.h"


Sprite *fieldSprite;
Sprite *selectedSprite;
u_long *dataTim[5];

struct Point {
    int x;
    int y;
} Cursor;

int isLockUpdate;

void drawTicTac();
void updateTicTac();
void initTicTac();
#endif //SIMPLE_PS1_GAMES_TIC_TAC_TOE_GAME_H
