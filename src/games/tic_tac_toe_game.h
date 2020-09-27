
#ifndef SIMPLE_PS1_GAMES_TIC_TAC_TOE_GAME_H
#define SIMPLE_PS1_GAMES_TIC_TAC_TOE_GAME_H
#include "../engine.h"
#include "../controller.h"

#define CROSS 1
#define CIRCLE 2


Sprite *fieldSprite;
Sprite *selectedSprite;
Sprite *crossSprite;
Sprite *circleSprite;
Sprite *lineSprite;
u_long *dataTim[5];

int indexI,indexJ;
struct Point {
    int x;
    int y;
} Cursor;

int fieldInfo[3][3];
int isLockUpdate;

void drawTicTac();
void updateTicTac();
void initTicTac();
#endif //SIMPLE_PS1_GAMES_TIC_TAC_TOE_GAME_H
