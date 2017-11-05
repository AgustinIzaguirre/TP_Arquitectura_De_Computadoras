#include <naiveConsole.h>
#include <lib.h>
#include <videoDriver.h> 
int isAlpha(unsigned char);
unsigned char keyCodes[55] = {' ','1','2','3','4','5','6','7','8','9','0','-','=',' ',' ','q','w','e','r','t','y','u','i','o','p','[',']','\n'
,' ','a','s','d','f','g','h','j','k','l',';','\'',' ',' ','\\','z','x','c','v','b','n','m',',','.','/',' ','*'};


void keyboard_handler() {
	_cli();
	unsigned char l = getKey();
	getKey();
	
	if(isAlpha(l));
		draw_char(keyCodes[l-1]);
	_sti();
}

int isAlpha(unsigned char l) {
	_cli();
	if((l>=16 && l <=25 )|| (l>=30 && l<= 38 )|| (l>=44 && l<=50)) {
		//ncNewline();
		//ncPrintDec(l);
		return 1;
	}
	_sti();
	return 0;
}

