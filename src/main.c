#include "engine.h"

void initialize();
void update();
void draw();

Color* color;
Color* blend_color;
u_long* data[3];
Sprite* sprites[2];

int main() {
    initialize();
    while(1) {
        update();
        clear_display();
        draw();
        display();
    }
}

void initialize() {
    initialize_heap();
    initialize_screen();
    initialize_pad();
    color_create(0, 0, 0, &color);
    set_background_color(color);
    cd_open();
    cd_read_file("SPLASH.TIM", &data[0]);
    cd_close();

    /*audio_init();
    audio_transfer_vag_to_spu((u_char *)data[0], SECTOR * 21, SPU_00CH);
    audio_play(SPU_00CH);*/

    sprite_create((u_char *)data[0], 160, 128, &sprites[0]);
    sprite_set_middle(sprites[0],63,40);

    //sprite_set_blend_rgb(sprites[0],0,255,0);
   // free3(data[0]);



}

void update() {

    /*pad_update();
    if(pad_check(Pad1Right)) {
        sprites[0]->rotate += ROT_ONE * 1;
    }
    if(pad_check(Pad1Left)) {
        sprites[0]->rotate -= ROT_ONE * 1;
    }*/

}

void draw() {
    draw_sprite(sprites[0]);
}