#ifndef _VIDEO_DRIVER_H_
#define _VIDEO_DRIVER_H_

#define RED_MASK 0x00FF0000
#define GREEN_MASK 0x00FF00
#define BLUE_MASK 0x0000FF


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
void setPointer(int x, int y);

void scrollUp(void);
void eraseLine(int y);
void copyLine(int to, int from);
//
void draw_horizontalTotalLine(int y);
void draw_verticalTotalLine(int x);
void draw_verticalLine(int x, int y0, int y1);
void draw_horizontalLine(int x0, int x1, int y);
void setBackgroundColor(Color color);
void draw_Line(int x1, int y1, int x2,int y2);
void cls();
void drawFunction(int a, int b, int c);
int getScreenHeigth(void);
int getScreenWidth(void);
void draw_char_position(uint8_t l, int x, int y);
Color hexaToColor(uint64_t color);
void printHexaNumber(uint64_t number);
char toHexa(uint64_t n);

#endif