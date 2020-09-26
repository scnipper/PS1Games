#include "core.h"
#include "controller.h"
#include "games/tic_tac_toe_game.h"
#include "screen_selector.h"


Color *color;
Color *blend_color;
u_long *data[1];
Sprite *logoSprite;

u_long tick = 0;
int logoBlend = 0;
int isLogoShow;


void initLogo() {
    isLogoShow = 0;
    logoBlend = 0;
    tick = 0;
    color_create(0, 0, 0, &color);
    set_background_color(color);
    cd_open();
    cd_read_file("SPLASH.TIM", &data[0]);
    cd_close();

    /*audio_init();
    audio_transfer_vag_to_spu((u_char *)data[0], SECTOR * 21, SPU_00CH);
    audio_play(SPU_00CH);*/

    sprite_create((u_char *) data[0], 160, 128, &logoSprite);
    sprite_set_middle(logoSprite, 63, 40);


    // free3(data[0]);
}


void initialize() {
    initialize_heap();
    initialize_screen();
    initialize_pad();

    initLogo();


}

void updateLogo() {
    sprite_set_blend_rgb(logoSprite, logoBlend, logoBlend, logoBlend);
    if (!isLogoShow) {
        if (logoBlend < 128)
            logoBlend++;
        else {
            tick++;
            if (tick >= 10) {
                isLogoShow = 1;
            }
        }
    }

    if (isLogoShow) {
        logoBlend--;
        if (logoBlend <= 0) {
            logoBlend = 0;
            free3(logoSprite);
            clear_vram();
            setState(TIC_TAC);
        }
    }
}

void update() {

    /*pad_update();
    if(pad_check(Pad1Right)) {
        sprites[0]->rotate += ROT_ONE * 1;
    }
    if(pad_check(Pad1Left)) {
        sprites[0]->rotate -= ROT_ONE * 1;
    }*/


    switch (mainState) {
        case LOGO:
            updateLogo();
            break;
        case SELECT_SCREEN:
            updateScreenSelector();
            break;
        case TIC_TAC:
            updateTicTac();
            break;
    }


}

void drawLogo() {
    draw_sprite(logoSprite);
}

void draw() {
    switch (mainState) {
        case LOGO:
            drawLogo();
            break;
        case SELECT_SCREEN:
            drawScreenSelector();
            break;
        case TIC_TAC:
            drawTicTac();
            break;
    }
}


int main() {
    mainState = LOGO;
    initFuncs[LOGO] = initLogo;
    initFuncs[SELECT_SCREEN] = initScreenSelector;
    initFuncs[TIC_TAC] = initTicTac;

    initialize();
    while (1) {
        update();
        clear_display();
        draw();
        display();
    }
}