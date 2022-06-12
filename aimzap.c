// todo:
// [] change angle of the ball (y and x probably) whenever it's hit close to the goal line
// [] flash two frames (top and bottom) of the ball to put spin on it?
// [] add title screen with button holding down

#include "LIB/neslib.h"
#include "LIB/nesdoug.h"
#include "LIB/zaplib.h"
#include "aimzap.h"
#include "sprites.h"

void main(void)
{

	ppu_off(); // screen off

	pal_bg(palette_bg);	 //	load the palette
	pal_spr(palette_sp); //	load the palette
	set_vram_buffer();	 // do at least once, sets a pointer to a buffer

	bank_spr(1); // sprites use the 2nd tileset

	ppu_wait_nmi(); // wait

	game_mode = MODE_TITLE;

	//	music_play(0); // silence

	set_vram_buffer(); // points ppu update to vram_buffer, do this at least once

	ppu_on_all(); // turn on screen

	while (1)
	{

		while (game_mode == MODE_TITLE) // gameloop
		{
			ppu_wait_nmi(); // wait till beginning of the frame

			set_data_pointer(level); // we set level pointer outside
			draw_bg();

			game_mode = MODE_GAME;
		}
		while (game_mode == MODE_GAME) // gameloop
		{
			ppu_wait_nmi(); // wait till beginning of the frame

			read_input_triggers(); // read the input

			if (trigger1_pulled == 1)
			{
				// if there's a shot, read the zapper hits
				// this will take 4 frames to do
				read_zapper_hits();
			}

			draw_sprites();

			gray_line(); // debugging how much processing is used
		}
	}
}

void draw_sprites(void)
{
	shot_location_x = x_lookups[zap1_light_read_pattern_0];
	shot_location_y = y_lookups[zap1_light_read_pattern_0];
	oam_clear(); // clear the sprites

	// put a sprite wherever the player shot
	oam_meta_spr(shot_location_x, shot_location_y, smiley);
}

void read_input_triggers(void)
{
	zap1_hit_detected = 0;
	trigger1_pulled = 0;

	zap1_ready = pad1_zapper ^ 1; // XOR last frame, make sure not held down still

	// is trigger pulled?
	pad1_zapper = zap_shoot(0); // controller slot 1

	if ((pad1_zapper == 1) && (zap1_ready))
	{
		trigger1_pulled = 1;
	}
}

void read_zapper_hits(void)
{
	// only reads the hit for the zapper pulled

	// goes through 5 frames:
	// frame 1: all black
	// frame 2: halves
	// frame 3: quarters
	// frame 4: eights
	// frame 5: sixteenths

	// we read the zap_read for every frame
	// then we can binary search style know where
	// the player aimed at
	// and we'll draw a cute thing there.

	// clear all sprites
	oam_clear();

	// frame 0:
	ppu_mask(0x16); // BG off, won't happen till NEXT frame
	zap1_light_read_pattern_0 = 0;
	ppu_wait_nmi(); // wait till the top of the next frame

	// frame 1:
	set_data_pointer(level1);
	draw_bg();
	zap1_light_read_pattern_1 = zap_read(0);
	zap1_light_read_pattern_0 << 1;
	zap1_light_read_pattern_0 = zap1_light_read_pattern_0 | zap1_light_read_pattern_1;
	ppu_wait_nmi(); // wait till the top of the next frame

	// frame 2:
	set_data_pointer(level2);
	draw_bg();
	zap1_light_read_pattern_2 = zap_read(0);
	zap1_light_read_pattern_0 << 1;
	zap1_light_read_pattern_0 = zap1_light_read_pattern_0 | zap1_light_read_pattern_2;
	ppu_wait_nmi(); // wait till the top of the next frame

	// frame 3:
	set_data_pointer(level3);
	draw_bg();
	zap1_light_read_pattern_3 = zap_read(0);
	zap1_light_read_pattern_0 << 1;
	zap1_light_read_pattern_0 = zap1_light_read_pattern_0 | zap1_light_read_pattern_3;
	ppu_wait_nmi(); // wait till the top of the next frame

	// frame 4:
	set_data_pointer(level4);
	draw_bg();
	zap1_light_read_pattern_4 = zap_read(0);
	zap1_light_read_pattern_0 << 1;
	zap1_light_read_pattern_0 = zap1_light_read_pattern_0 | zap1_light_read_pattern_4;
	ppu_wait_nmi(); // wait till the top of the next frame

	// ALL DONE!

	set_data_pointer(level);
	draw_bg();
}

void draw_bg(void)
{
	ppu_off();	 // screen off
	oam_clear(); // clear all sprites

	set_mt_pointer(metatiles);
	// memcpy(c_map, level, 240);

	// draw the tiles
	for (y = 0;; y += 0x20)
	{
		for (x = 0;; x += 0x20)
		{
			address = get_ppu_addr(0, x, y);
			index = (y & 0xf0) + (x >> 4);
			buffer_4_mt(address, index); // ppu_address, index to the data
			flush_vram_update2();
			if (x == 0xe0)
				break;
		}
		if (y == 0xe0)
			break;
	}

	ppu_on_all();
}
