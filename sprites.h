
#include "CSV/level.c"
#include "CSV/level1.c"
#include "CSV/level2.c"
#include "CSV/level3.c"
#include "CSV/level4.c"

const unsigned char palette_bg[] = {
		0x0f, 0x0f, 0x0f, 0x0f, // black
		0x30, 0x30, 0x30, 0x30, // white
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
		2, 2, 2, 2, 0,
		2, 2, 2, 2, 1,
		2, 2, 2, 2, 2,
		2, 2, 2, 2, 3,
		4, 4, 4, 4, 1,
		9, 9, 9, 9, 2,
		5, 6, 8, 7, 1,
		5, 6, 8, 7, 0};

const unsigned char smiley[] = {
		0xff, 0xff, 0x02, 0,
		7, 0xff, 0x03, 0,
		0xff, 7, 0x12, 0,
		7, 7, 0x13, 0,
		128};