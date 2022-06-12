// variables
#define LEFT_BOUNDARY 0x0500
#define RIGHT_BOUNDARY 0xe000
#define TOP_BOUNDARY 0xb000
#define BOTTOM_BOUNDARY 0x2000
#define MIDDLE_SCREEN 0x7000

#pragma bss-name(push, "ZEROPAGE")

unsigned char frames_to_wait = 5; // used to calibrate the screen for modern displays
unsigned char pad1_zapper;
unsigned char zap1_ready; // wait till it's 0
unsigned char zap1_hit_detected;
unsigned char trigger1_pulled;
// unsigned char pad2_zapper;
// unsigned char zap2_ready; //wait till it's 0
// unsigned char zap2_hit_detected;
unsigned char shot_location_x;
unsigned char shot_location_y;
unsigned char zap1_light_read_pattern_0;
unsigned char zap1_light_read_pattern_1;
unsigned char zap1_light_read_pattern_2;
unsigned char zap1_light_read_pattern_3;
unsigned char zap1_light_read_pattern_4;
unsigned char zap1_light_read_pattern_5;

const unsigned char x_lookups[]={
0,0,0x40,0x40,0x40,0x40,0,0,0xa0,0xa0,0x80,0x80,0x80,0x80,0xa0,0xa0
};
const unsigned char y_lookups[]={
0,0x40,0x40,0,0xa0,0x80,0x80,0xa0,0xa0,0x80,0x80,0xa0,0,0x40,0x40,0
};

//0000 	0,0
//0001 0,40
//0010 40,40
//0011 40,0
//0100 40,a0
//0101 40,80
//0110 0,80
//0111 0,a0
//1000 a0,a0
//1001 a0,80
//1010 80,80
//1011 80,a0
//1100 80,0
//1101 80,40
//1110 a0,40
//1111 a0,0

// debuging with pad
unsigned char pad1;
unsigned char pad1_new;

unsigned char game_mode;
enum
{
	MODE_TITLE,
	MODE_GAME,
	MODE_PAUSE,
	MODE_END,
	MODE_GAME_OVER,
};

// room loader code
int address;
unsigned char x;
unsigned char y;
unsigned char index = 0;

#pragma bss-name(push, "BSS")

unsigned char c_map[240]; // collision map

// PROTOTYPES
void read_input_triggers(void);
void read_zapper_hits(void);
void draw_sprites(void);
void draw_bg(void);
