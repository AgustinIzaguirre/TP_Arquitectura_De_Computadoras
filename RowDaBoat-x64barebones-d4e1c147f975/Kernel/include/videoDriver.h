#ifndef _VIDEO_DRIVER_H_
#define _VIDEO_DRIVER_H_


typedef struct Color {
	uint8_t blue;
	uint8_t green;
	uint8_t red;
} Color;

typedef struct pointer {
	int x;
	int y;
}Pointer;

void draw_pixel(int x, int y);
void draw_pixel_with_color(int x, int y,Color color);
void draw_char(uint8_t l); 
void draw_word(char * word,int x, int y);
void draw_char_with_color(uint8_t l, int x, int y,Color letter_color, Color background_color);
void erase_char();
void newLine();

#endif