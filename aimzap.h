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
unsigned char shot_location;
unsigned char zap1_light_read_pattern;

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
