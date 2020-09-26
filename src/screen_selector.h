#ifndef SIMPLE_PS1_GAMES_SCREEN_SELECTOR_H
#define SIMPLE_PS1_GAMES_SCREEN_SELECTOR_H
#include "engine.h"

Color* selectedScreenBg;


void initScreenSelector() {
    color_create(0,50,255,&selectedScreenBg);
    set_background_color(selectedScreenBg);
}

void drawScreenSelector() {

}

void updateScreenSelector() {

}
#endif //SIMPLE_PS1_GAMES_SCREEN_SELECTOR_H
