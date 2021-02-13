
#ifndef SIMPLE_PS1_GAMES_TIC_TAC_TOE_GAME_H
#define SIMPLE_PS1_GAMES_TIC_TAC_TOE_GAME_H
#include "../engine.h"
#include "../controller.h"
#include <rand.h>

#define CROSS 1
#define CIRCLE 2
#define SIZE_FIELD 3


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
struct Point pos[SIZE_FIELD][SIZE_FIELD];
// field with cross and circles
int fieldInfo[SIZE_FIELD][SIZE_FIELD];
int isLockUpdate;

int scoreCircle;
int scoreCross;

int fontCircleId;
int fontCrossId;
int currentFigureTicTac;

void drawTicTac();
void updateTicTac();
void initTicTac();
void drawTicTacField();
void drawScoreTicTac();
void clearField();
void winGame(int typeFigure);
void checkWinCombination();
void setField(int typeFigure);
int countEmptySlot();

void addToRandomEmptyPlace();

#endif //SIMPLE_PS1_GAMES_TIC_TAC_TOE_GAME_H
