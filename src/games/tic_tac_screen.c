#include "tic_tac_screen.h"



void freeSprites() {
    indexFor = 0;

    for (; indexFor < 7; ++indexFor) {
        free3(spritesPool[indexFor]);
    }
}

void drawTicTacScreen(){
    draw_sprite(spritesPool[LOGO_TIC_SPRITE]);
    draw_sprite(curSelectedMenu == 1 ? spritesPool[PL1_SEL_SPRITE]  :spritesPool[PL1_SPRITE]);
    draw_sprite(curSelectedMenu == 2 ? spritesPool[PL2_SEL_SPRITE] : spritesPool[PL2_SPRITE]);
    draw_sprite(spritesPool[BACK_SPRITE_1]);
    draw_sprite(spritesPool[BACK_SPRITE_2]);
}
void updateTicTacScreen(){

    pad_update();
    if (pad_check(Pad1Up)) {
        curSelectedMenu--;
        if(curSelectedMenu < 1) curSelectedMenu = 1;
    }
    if (pad_check(Pad1Down)) {
        curSelectedMenu++;
        if(curSelectedMenu > 2) curSelectedMenu = 2;
    }
    if (pad_check(Pad1Cross)) {
        clear_vram();
        freeSprites();
        gameType = curSelectedMenu;
        setState(TIC_TAC);
    }
}
void initTicTacScreen(){
    curSelectedMenu = 1;

    cd_open();

    cd_read_file("TIC_TAC_PL1", &dataPool[PL1_SPRITE]);
    cd_read_file("TIC_TAC_P1S", &dataPool[PL1_SEL_SPRITE]);
    cd_read_file("TIC_TAC_PL2", &dataPool[PL2_SPRITE]);
    cd_read_file("TIC_TAC_P2S", &dataPool[PL2_SEL_SPRITE]);
    cd_read_file("TIC_TAC_B1", &dataPool[BACK_SPRITE_1]);
    cd_read_file("TIC_TAC_B2", &dataPool[BACK_SPRITE_2]);
    cd_read_file("TIC_TAC_L", &dataPool[LOGO_TIC_SPRITE]);
    cd_close();

    sprite_create((u_char *) dataPool[PL1_SPRITE], 104, 91, &spritesPool[PL1_SPRITE]);
    sprite_create((u_char *) dataPool[PL1_SEL_SPRITE], 104, 91, &spritesPool[PL1_SEL_SPRITE]);
    sprite_create((u_char *) dataPool[PL2_SPRITE], 104, 141, &spritesPool[PL2_SPRITE]);
    sprite_create((u_char *) dataPool[PL2_SEL_SPRITE], 104, 141, &spritesPool[PL2_SEL_SPRITE]);
    sprite_create((u_char *) dataPool[BACK_SPRITE_1], 0, 0, &spritesPool[BACK_SPRITE_1]);
    sprite_create((u_char *) dataPool[BACK_SPRITE_2], 160, 0, &spritesPool[BACK_SPRITE_2]);
    sprite_create((u_char *) dataPool[LOGO_TIC_SPRITE], 43, 16, &spritesPool[LOGO_TIC_SPRITE]);
    indexFor = 0;


    for (; indexFor < 7; ++indexFor) {
        free3(dataPool[indexFor]);
    }


}