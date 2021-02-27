#ifndef SIMPLE_PS1_GAMES_SCREEN_SELECTOR_H
#define SIMPLE_PS1_GAMES_SCREEN_SELECTOR_H
#include "../core.h"


#define MAIN_BACK_1     0
#define MAIN_BACK_2     1
#define MAIN_LOGO       2
#define MAIN_NEXT_TRACK 3
#define MAIN_PREV_TRACK 4
#define MAIN_SEL_ARROW  5
#define MAIN_SNAKE      6
#define MAIN_TIC        7
Color* selectedScreenBg;

int indexFor;

void initScreenSelector();

void drawScreenSelector();

void updateScreenSelector();
#endif //SIMPLE_PS1_GAMES_SCREEN_SELECTOR_H
