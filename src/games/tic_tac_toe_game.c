#include "tic_tac_toe_game.h"


void drawTicTac() {

        draw_sprite(selectedSprite);



        draw_sprite(fieldSprite);
        drawTicTacField();
        drawScoreTicTac();

}

/*
 * Drawing score
 */
void drawScoreTicTac() {

    sprite_set_position(crossSprite,14,50);
    crossSprite->scalex = ONE / 2;
    crossSprite->scaley = ONE / 2;
    draw_sprite(crossSprite);
    crossSprite->scalex = ONE;
    crossSprite->scaley = ONE;


    sprite_set_position(circleSprite,14,170);
    circleSprite->scalex = ONE / 2;
    circleSprite->scaley = ONE / 2;
    draw_sprite(circleSprite);
    circleSprite->scalex = ONE;
    circleSprite->scaley = ONE;

    FntPrint(fontCrossId,"%d",scoreCross);
    FntFlush(fontCrossId);



    FntPrint(fontCircleId,"%d",scoreCircle);
    FntFlush(fontCircleId);

}

/*
 * Drawing tictac field
 */
void drawTicTacField() {
    for (indexI = 0; indexI < 3; ++indexI) {
        for (indexJ = 0; indexJ < 3; ++indexJ) {
            struct Point p = pos[indexI][indexJ];
            if(fieldInfo[indexI][indexJ] == CROSS) {
                sprite_set_position(crossSprite,p.x,p.y);

                draw_sprite(crossSprite);
            } else if(fieldInfo[indexI][indexJ] == CIRCLE) {
                sprite_set_position(circleSprite,p.x,p.y);

                draw_sprite(circleSprite);
            }
        }
    }

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

    sprite_set_position(selectedSprite,85 + Cursor.x * 85,7 + Cursor.y *85);
}
void initTicTac() {


    Color *bg;
    color_create(0, 140, 255, &bg);
    set_background_color(bg);

    scoreCircle = 0;
    scoreCross = 0;
    FntLoad(960, 256);
    fontCrossId = FntOpen(25, 80, 30, 30, 0, 512);
    fontCircleId = FntOpen(25, 200, 30, 30, 0, 512);

    for (indexI = 0; indexI < 3; ++indexI) {
        for (indexJ = 0; indexJ < 3; ++indexJ) {
            pos[indexI][indexJ].x = 90 + indexI * 85;
            pos[indexI][indexJ].y = 7 + indexJ *85;
        }
    }

    cd_open();

    cd_read_file("FIELD.TIM", &dataTim[0]);
    cd_read_file("SELECTED.TIM", &dataTim[1]);
    cd_read_file("CROSS.TIM", &dataTim[2]);
    cd_read_file("CIRCLE.TIM", &dataTim[3]);
    cd_read_file("LINE.TIM", &dataTim[4]);
    cd_close();

    sprite_create((u_char *) dataTim[0], 80, 0, &fieldSprite);
    sprite_create((u_char *) dataTim[1], 85, 7, &selectedSprite);
    sprite_create((u_char *) dataTim[2], 85, 7, &crossSprite);
    sprite_create((u_char *) dataTim[3], 85, 7, &circleSprite);
    sprite_create((u_char *) dataTim[4], 85, 7, &lineSprite);

    for (indexI = 0; indexI < 5; ++indexI) {
        free3(dataTim[indexI]);
    }

}