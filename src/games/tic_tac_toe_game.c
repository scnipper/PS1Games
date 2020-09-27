#include "tic_tac_toe_game.h"

void drawTicTac() {
    draw_sprite(selectedSprite);



    for (indexI = 0; indexI < 3; ++indexI) {
        for (indexJ = 0; indexJ < 3; ++indexJ) {
            if(fieldInfo[indexI][indexJ] == CROSS) {
                sprite_set_position(crossSprite,60 + indexI * 85,7 + indexJ *85);

                draw_sprite(crossSprite);
            } else if(fieldInfo[indexI][indexJ] == CIRCLE) {
                sprite_set_position(circleSprite,60 + indexI * 85,7 + indexJ *85);

                draw_sprite(circleSprite);
            }
        }
    }

    draw_sprite(fieldSprite);
}
void updateTicTac() {
    if(!isLockUpdate) {
        pad_update();
        if(pad_check(Pad1Right)) {
            isLockUpdate = 10;
            Cursor.x++;
            if(Cursor.x >=3) {
                Cursor.x = 2;
            }
        }
        if(pad_check(Pad1Left)) {
            isLockUpdate = 10;
            Cursor.x--;
            if(Cursor.x < 0) {
                Cursor.x = 0;
            }
        }

        if(pad_check(Pad1Down)) {
            isLockUpdate = 10;
            Cursor.y++;
            if(Cursor.y >=3) {
                Cursor.y = 2;
            }
        }
        if(pad_check(Pad1Up)) {
            isLockUpdate = 10;
            Cursor.y--;
            if(Cursor.y < 0) {
                Cursor.y = 0;
            }
        }
    }

    if(pad_check(Pad1Cross)) {
        fieldInfo[Cursor.x][Cursor.y] = CROSS;
    }
    if(pad_check(Pad1Circle)) {
        fieldInfo[Cursor.x][Cursor.y] = CIRCLE;
    }
    if(isLockUpdate > 0) {
        isLockUpdate--;
    }

    sprite_set_position(selectedSprite,55 + Cursor.x * 85,7 + Cursor.y *85);
}
void initTicTac() {


    Color *bg;
    color_create(0, 140, 255, &bg);
    set_background_color(bg);

    cd_open();

    cd_read_file("FIELD.TIM", &dataTim[0]);
    cd_read_file("SELECTED.TIM", &dataTim[1]);
    cd_read_file("CROSS.TIM", &dataTim[2]);
    cd_read_file("CIRCLE.TIM", &dataTim[3]);
    cd_read_file("LINE.TIM", &dataTim[4]);
    cd_close();

    sprite_create((u_char *) dataTim[0], 50, 0, &fieldSprite);
    sprite_create((u_char *) dataTim[1], 55, 7, &selectedSprite);
    sprite_create((u_char *) dataTim[2], 55, 7, &crossSprite);
    sprite_create((u_char *) dataTim[3], 55, 7, &circleSprite);
    sprite_create((u_char *) dataTim[4], 55, 7, &lineSprite);

}