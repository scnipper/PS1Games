#include "tic_tac_screen.h"



void freeSprites() {
    free3(logoTicSprite);
    free3(backSprite1);
    free3(backSprite2);
    free3(pl2SelectedSprite);
    free3(pl1SelectedSprite);
    free3(pl1Sprite);
    free3(pl2Sprite);

    logoTicSprite = NULL;
    backSprite1 = NULL;
    backSprite2 = NULL;
    pl2SelectedSprite = NULL;
    pl1SelectedSprite = NULL;
    pl1Sprite = NULL;
    pl2Sprite = NULL;
}

void drawTicTacScreen(){
    draw_sprite(logoTicSprite);
    draw_sprite(curSelectedMenu == 1 ? pl1SelectedSprite  :pl1Sprite);
    draw_sprite(curSelectedMenu == 2 ? pl2SelectedSprite : pl2Sprite);
    draw_sprite(backSprite1);
    draw_sprite(backSprite2);
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
    if (pad_check(Pad1Cross) && waitStartTicTac == 0) {
        printf("load tictac\n");
       // pause = 1;
        clear_vram();
        freeSprites();

       // initialize_heap();

       // setState(TIC_TAC);

        waitStartTicTac = 2000;
    }
    if(waitStartTicTac > 0) {
        waitStartTicTac--;
        printf("wait %d \n",waitStartTicTac);
        if(waitStartTicTac == 0) {
            setState(TIC_TAC);

            pause = 0;
        }
    }
}
void initTicTacScreen(){
    curSelectedMenu = 1;

    cd_open();

    cd_read_file("TIC_TAC_PL1", &dataTimScreen[0]);
    cd_read_file("TIC_TAC_P1S", &dataTimScreen[1]);
    cd_read_file("TIC_TAC_PL2", &dataTimScreen[2]);
    cd_read_file("TIC_TAC_P2S", &dataTimScreen[3]);
    cd_read_file("TIC_TAC_B1", &dataTimScreen[4]);
    cd_read_file("TIC_TAC_B2", &dataTimScreen[5]);
    cd_read_file("TIC_TAC_L", &dataTimScreen[6]);
    cd_close();

    sprite_create((u_char *) dataTimScreen[0], 104, 91, &pl1Sprite);
    sprite_create((u_char *) dataTimScreen[1], 104, 91, &pl1SelectedSprite);
    sprite_create((u_char *) dataTimScreen[2], 104, 141, &pl2Sprite);
    sprite_create((u_char *) dataTimScreen[3], 104, 141, &pl2SelectedSprite);
    sprite_create((u_char *) dataTimScreen[4], 0, 0, &backSprite1);
    sprite_create((u_char *) dataTimScreen[5], 160, 0, &backSprite2);
    sprite_create((u_char *) dataTimScreen[6], 43, 16, &logoTicSprite);
    indexFor = 0;

    sprites[0] = pl1Sprite;
    sprites[1] = pl1SelectedSprite;
    sprites[2] = pl2Sprite;
    sprites[3] = pl2SelectedSprite;
    sprites[4] = backSprite1;
    sprites[5] = backSprite2;
    sprites[6] = logoTicSprite;

    for (; indexFor < 7; ++indexFor) {
        free3(dataTimScreen[indexFor]);
    }


}