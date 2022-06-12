
#include "CSV/level.c"

const unsigned char palette_bg[] = {
		0x0f, 0x00, 0x10, 0x30, // black, gray, lt gray, white
		0x0f, 0x07, 0x17, 0x27, // oranges
		0x0f, 0x02, 0x12, 0x22, // blues
		0x0f, 0x09, 0x19, 0x29, // greens
};

const unsigned char palette_sp[] = {
		0x0f, 0x07, 0x28, 0x38, // dk brown, yellow, white yellow
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0};

// 5 bytes per metatile definition, tile TL, TR, BL, BR, palette 0-3
// T means top, B means bottom, L left,R right
// 51 maximum # of metatiles = 255 bytes

const unsigned char metatiles[] = {
		2, 2, 2, 2, 3,
		4, 4, 4, 4, 1,
		9, 9, 9, 9, 2,
		5, 6, 8, 7, 1,
		5, 6, 8, 7, 0};

const unsigned char WhiteBox[] = {
		0, 0, 0xcb, 3 | OAM_FLIP_H,
		8, 0, 0xcb, 3,
		0, 8, 0xda, 3,
		8, 8, 0xda, 3 | OAM_FLIP_H,
		128};