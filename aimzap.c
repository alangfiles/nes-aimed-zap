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
			// todo, title stuff
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
	oam_clear(); // clear the sprites
	// put a sprite wherever the player shot
	oam_meta_spr(0, 0, WhiteBox);
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

	// debug code (for using controller to shoot and miss)
	//  pad1 = pad_poll(0);
	//  pad1_new = get_pad_new(0);

	// if ((pad1_new & PAD_A) && zap1_cooldown == 0) //((pad1_zapper) && (zap1_ready));
	// {
	// 	trigger1_pulled = 1;
	// }
	// if ((pad1_new & PAD_B) && zap2_cooldown == 0) //((pad2_zapper) && (zap2_ready));
	// {
	// 	trigger2_pulled = 1;
	// }
}

void read_zapper_hits(void)
{
	// only reads the hit for the zapper pulled
	// this should be the read code:
	if (trigger1_pulled == 1)
	{
		zap1_hit_detected = zap_read(0); // look for light in zapper, port 1
																		 // debug controller read code
																		 //  if (pad1_new & PAD_A)
																		 //  {
																		 //  	zap1_hit_detected = 1;
																		 //  }
	}
}

void draw_bg(void)
{
	ppu_off();	 // screen off
	oam_clear(); // clear all sprites

	set_mt_pointer(metatiles);
	set_data_pointer(level);
	memcpy(c_map, level, 240);

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
