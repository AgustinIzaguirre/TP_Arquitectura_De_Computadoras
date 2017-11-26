#ifndef _STDLIB_H_
#define _STDLIB_H_

#include <stdint.h>


int isNum(char c);
int isAlpha(char c);
int strlen(const char * str);
int strcpy(char *from, char *to);
int strcmp(char * array1, char * array2);
void strrev(char * str);
void intToStr(int num,char * ret);
void printf(const char * str,...);
void putchar(const char c);

#endif
