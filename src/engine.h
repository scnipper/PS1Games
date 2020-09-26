/*
 * constants.h
 *
 * Thanks to ORION for his well explained blog and awesome PSX library. (http://onorisoft.free.fr)
 * Thanks to Lameguy64 for his amazing tools and extensive PSX knowledge, free software mindset. (https://github.com/Lameguy64)
 * Thanks to whoever wrote LIBOVR.PDF and LIBREF.PDF back in the day.
 * Thanks to everybody from psxdev.net. <3
 * Big thanks to Shadow for making this possible. 
 * All of you are legends.
 * 
 *  Created on: Oct 8, 2016
 *      Author: Wituz
 */

#ifndef ENGINE_H
#define ENGINE_H

#include <stdlib.h>
#include <stdio.h>
#include <LIBGTE.H>
#include <LIBGPU.H>
#include <LIBGS.H>
#include <LIBETC.H>
#include <LIBSPU.H>
#include <LIBDS.H>
#include <STRINGS.H>
#include <SYS/TYPES.H>

unsigned long __ramsize; // 2 Megabytes of RAM
unsigned long __stacksize; // 16 Kilobytes of Stack

#define SECTOR 2048
#define OT_LENGTH 1
#define PACKETMAX 300
#define TYPE_LINE 0
#define TYPE_BOX 1
#define SCREEN_MODE_PAL 0
#define SCREEN_MODE_NTSC 1
#define DEBUG 0
#define SOUND_MALLOC_MAX 10
#define ROT_ONE 4096
#define Sprite GsSPRITE

typedef struct {
	int r;
	int g;
	int b;
} Color;

typedef struct {
	LINE_F2 line;
	int type;
} Line;

typedef struct {
	Line line[4];
	int type;
} Box;

typedef struct {
	RECT rect;
	RECT crect;
	GsIMAGE tim_data;
	GsSPRITE sprite;
} Image;

int 		  SCREEN_WIDTH, SCREEN_HEIGHT;
int 		  didInitDs;
GsOT 		  orderingTable[2];
GsOT_TAG  	  minorOrderingTable[2][1<<OT_LENGTH];
PACKET 		  GPUOutputPacket[2][PACKETMAX];
short 		  currentBuffer;
Color* 		  systemBackgroundColor;
SpuCommonAttr l_c_attr;
SpuVoiceAttr  g_s_attr;
unsigned long l_vag1_spu_addr;

void cd_open();

void cd_close();

void cd_read_file(unsigned char* file_path, u_long** file);

void audio_init();

void audio_transfer_vag_to_spu(char* sound, int sound_size, int voice_channel);

void audio_play(int voice_channel);

void audio_free(unsigned long spu_address);

void sprite_create(unsigned char imageData[], int x, int y, GsSPRITE **sprite);

void sprite_set_rotation(Sprite* sprite, int rotation);

void sprite_set_middle(Sprite* sprite, int relative_x, int relative_y);

void sprite_set_position(Sprite* sprite, int x, int y);

void sprite_set_blend_color(Sprite* sprite, Color* color);

void sprite_set_blend_rgb(Sprite* sprite, int r, int g, int b);

void color_create(int r, int g, int b, Color** color);

void line_create(Color* color, int x1, int y1, int x2, int y2, Line* line);

void box_create(Color *color, int x1, int y1, int x2, int y2, Box* box);

void line_move(Line* line, int x1, int y1, int x2, int y2);

void box_move(Box* box, int x1, int y1);


void draw_line(Line *line);

void draw_box(Box *box);

void draw_sprite(Sprite *sprite);

//Set the screen mode to either SCREEN_MODE_PAL or SCREEN_MODE_NTSC
void set_screen_mode(int mode);

void set_background_color(Color *color);

void initialize_heap();

void initialize_ordering_table();

void clear_vram();

void initialize_screen();

void initialize_debug_font();

void clear_display();

void display();

#endif