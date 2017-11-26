#ifndef _PLOTTER_H_
#define _PLOTTER_H_

#include <stdint.h>

#define RED_MASK 0x00FF0000
#define GREEN_MASK 0x00FF00
#define BLUE_MASK 0x0000FF
#define CHAR_WIDTH 8
#define CHAR_HEIGHT 16

typedef struct Color {
	uint64_t blue;
	uint64_t green;
	uint64_t red;
} Color;

typedef struct pointer {
	int x;
	int y;
}Pointer;



void draw_verticalTotalLine(int x);
void draw_horizontalTotalLine(int y);
void draw_verticalLine(int x, int y0, int y1);
void draw_horizontalLine(int x0, int x1, int y);
void draw_pixel_with_color(int x, int y,Color color);
void draw_pixel(int x, int y);

uint64_t ColorToHexa(Color color);
Color hexaToColor(uint64_t color);
void drawFunction(int a, int b, int c);
void drawAxis();
void cls();
uint64_t getScreenWidht();
uint64_t getScreenHeight();

#endif