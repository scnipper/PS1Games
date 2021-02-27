#include "screen_selector.h"
void initScreenSelector() {
    color_create(0,50,255,&selectedScreenBg);
    set_background_color(selectedScreenBg);


    cd_open();

    cd_read_file("MA_BA_1", &dataPool[MAIN_BACK_1]);
    cd_read_file("MA_BA_2", &dataPool[MAIN_BACK_2]);
    cd_read_file("MA_LOGO", &dataPool[MAIN_LOGO]);
    cd_read_file("MA_NEXT_TR", &dataPool[MAIN_NEXT_TRACK]);
    cd_read_file("MA_PREV_TR", &dataPool[MAIN_PREV_TRACK]);
    cd_read_file("MA_SEL_ARR", &dataPool[MAIN_SEL_ARROW]);
    cd_read_file("MA_SANKE", &dataPool[MAIN_SNAKE]);
    cd_read_file("MA_TIC", &dataPool[MAIN_TIC]);
    cd_close();

    sprite_create((u_char *) dataPool[MAIN_BACK_1], 0, 0, &spritesPool[MAIN_BACK_1]);
    sprite_create((u_char *) dataPool[MAIN_BACK_2], 160, 0, &spritesPool[MAIN_BACK_2]);
    sprite_create((u_char *) dataPool[MAIN_LOGO], 53, 23, &spritesPool[MAIN_LOGO]);
    sprite_create((u_char *) dataPool[MAIN_NEXT_TRACK], 233, 217, &spritesPool[MAIN_NEXT_TRACK]);
    sprite_create((u_char *) dataPool[MAIN_PREV_TRACK], 8, 220, &spritesPool[MAIN_PREV_TRACK]);
    sprite_create((u_char *) dataPool[MAIN_SEL_ARROW], 32, 86, &spritesPool[MAIN_SEL_ARROW]);
    sprite_create((u_char *) dataPool[MAIN_SNAKE], 52, 118, &spritesPool[MAIN_SNAKE]);
    sprite_create((u_char *) dataPool[MAIN_TIC], 52, 87, &spritesPool[MAIN_TIC]);
    indexFor = 0;


    for (; indexFor < 8; ++indexFor) {
        free3(dataPool[indexFor]);
    }
}

void drawScreenSelector() {
    draw_sprite(spritesPool[MAIN_SNAKE]);
    draw_sprite(spritesPool[MAIN_TIC]);
    draw_sprite(spritesPool[MAIN_SEL_ARROW]);
    draw_sprite(spritesPool[MAIN_PREV_TRACK]);
    draw_sprite(spritesPool[MAIN_NEXT_TRACK]);
    draw_sprite(spritesPool[MAIN_LOGO]);
    draw_sprite(spritesPool[MAIN_BACK_1]);
    draw_sprite(spritesPool[MAIN_BACK_2]);

}

void updateScreenSelector() {

}
