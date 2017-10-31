#include <naiveConsole.h>
#include <lib.h>

unsigned char keyCodes[55] = {' ','1','2','3','4','5','6','7','8','9','0','-','=',' ',' ','q','w','e','r','t','y','u','i','o','p','[',']','\n'
,' ','a','s','d','f','g','h','j','k','l',';','\'',' ',' ','\\','z','x','c','v','b','n','m',',','.','/',' ','*'};

void readKeyboard() {
	int i =0;
	unsigned char l;
	while(i<10) {
		l = getKey();
		ncPrintChar(keyCodes[l-1]);
		//i++;
	}
}

void keyboard_handler() {
	unsigned char l = getKey();
	ncPrintChar(keyCodes[l-1]);
}

