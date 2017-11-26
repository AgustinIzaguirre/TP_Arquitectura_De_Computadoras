#ifndef _SHELL_H_
#define _SHELL_H_

#define CHAR_HEIGHT 16

#define EXIT 0
#define TIME 1
#define DATE 2
#define CLEAR 3
#define HELP 4
#define ECHO 5
#define LINEAR 6
#define QUADRATIC 7
#define COLOR 8
#define TEST 9
#define COMMAND_MAX_LENGTH 10
#define COMMANDS_QUANTITY 10
#define COMMANDS_MAX_ARGS 50
#define MAX_LINEAR_INTS 2
#define MAX_QUADRATIC_INTS 3
#define MAX_COLOR_INTS 3
#define ID_INTS 1


void shell(void);
void setUpShell(void) ;
void printPrompt(void);
int getCommands(void);
int readArgs(char * args);
int getInts(int totalArgs);
int getNumber(char* args, int* pos);
void functionScreen(int a, int b, int c);
int valid(int from,int to,int size);
#endif