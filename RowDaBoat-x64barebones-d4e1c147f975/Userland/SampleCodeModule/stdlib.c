//stdlib.c
#include <stdint.h>
#include <stdlib.h>
#include <plotter.h>
#include <stdarg.h>
extern uint64_t _int80(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9);

int isAlpha(char c){
	return ((c>='A' && c<='Z') || (c>='a' && c<='z'));
}

int isNum(char c){
	return (c>='0' && c<='9');
}

int isSpace(char c){
	return (c=' ');
}

void intToStr(int num,char * ret){
	int dig=0;
	char aux;
	if(num!=0){
		if(num<0){
			num=-num;
			ret[0]='-';
			dig++;
		}
		while(num!=0){
			ret[dig]=(num%10)+'0';
			num=num/10;
			dig++;
		}
		for(int x=0;x<dig/2;x++){
			aux=ret[x];
			ret[x]=ret[dig-x-1];
			ret[dig-x-1]=aux;
		}
		ret[dig]=0;
	}else{
		ret[0]='0';
	}	
}
void strrev(char * str){
	int length= strlen(str);
	char aux[length];
	int i;
	strcpy(str,aux);

	for (i = 0; i < length; i++) {
		str[length - 1 - i] = aux[i];
	}
}

int strlen(const char * str){
	int i=0;
	while(str[i]!= '\0'){
		i++;
	}
	return i;
}

int strcpy(char *from, char *to){
	int i=0;
	for (i=0;from[i]!='\0';i++){
		to[i]=from[i];
	}
	to[i] = 0;
	return i;
}

int strcmp(char * array1, char * array2) {
	int i=0;
	for (i=0;array2[i]!='\0';i++){
		if(array1[i]!=array2[i])
			return 0;
	}
	return array1[i] == array2[i];
}

void printf(const char * str,...){
	char num[12];
	va_list valist;
	va_start (valist,str);
	int length=strlen(str);
	int state=0;
	for(int x=0;x<length;x++){
		if(state==0){
			if(str[x]!= '%')
				putchar(str[x]);
			else
				state=1;
		}else{
			switch(str[x]){
				case 'd':
					intToStr(va_arg (valist, int),num);
					int index=0;
					while(num[index]!=0)
						putchar(num[index++]);
					state=0;
					break;
				case 'c':
					putchar((char)(va_arg(valist,int)));
					state=0;
					break;
				case 's':
					printf(va_arg(valist, char*));
					state = 0;
					break;
				default:	
					putchar('%');
					putchar(str[x]);
					state=0;
					break;
			}
		}

	}	
	va_end(valist);
}

void putchar(const char c){
	_int80(1,1,&c,1,0,0);
}


int getchar() {
	char c;
	_int80(0,0,&c,1,0,0);
	return c;
}

// /*
// ** Lee una línea de entrada estándar de longitud como mucho maxlen y la guarda en str.
// */
// int readline(char *str, unsigned int maxlen) {
//     unsigned int i;
//     int c;
//     for (i = 0; i < maxlen-1 && (c = getchar()) != '\n'; i++) 
// 			str[i] = c;
//     str[i] = '\0';
//     return i;
// }

// int scanf(const char* str, ...){
// 	va_list args;
// 	va_start(args,c);

// 	int ret = 0;
// 	int flag = 0;
// 	int i = 0;
// 	char buffer[MAX];
// 	int j = 0;
// 	char currentChar;

// 	while((currentChar = getchar()) != '\n'){
// 		if(currentChar == '\b'){
// 			if(j>0){
// 				buffer[--j] = 0;
// 				printf("\b");
// 			}
// 		}else{
// 			if(j < MAX){
// 				buffer[j++]	= currentChar;
// 				putChar(currentChar);
// 			}
// 		}
// 	}
// 	buffer[j] = 0;
// 	j = 0;

// 	while(c[i]!=0&&ret>=0){
// 		switch(c[i]) {
// 			case '%':
// 				if(flag) {
// 					if(buffer[j]!='%')
// 						ret = -1;
// 					else
// 						j++;
// 				} else {
// 					flag = 1;
// 				}
// 				break;
// 			case 'd':
// 				if(flag){
// 					if(getNumber(va_arg(args,int*),buffer,&j))
// 						ret++;
// 					else
// 						ret = -1;
// 					flag = 0;
// 				} else {
// 					if(buffer[j]!='d')
// 						ret = -1;
// 					else
// 						j++;
// 				}
// 				break;
// 			case 's':
// 			if(flag){
// 					j += copyString(buffer+j,va_arg(args,char*));
// 					ret++;
// 					flag = 0;
// 				} else {
// 					if(buffer[j]!='s')
// 						ret = -1;
// 					else
// 						j++;
// 				}
// 				break;
// 			default:
// 				if(buffer[j]!=c[i])
// 					ret = -1;
// 				else
// 					j++;
// 		}
// 		i++;
// 	}
// 	printf("\n");
// 	va_end(args);
// 	return ret;
// }

// int scanf(const char *format, ...) {
// 	int i, j, num;
// 	int argc = 0;
// 	int *p;
// 	char *str;
// 	char aux[BUFFER_SIZE];
// 	va_list args;
// 	va_start(args, format);

// 	readline(aux, BUFFER_SIZE);

// 	for (i = j = 0; aux[j] != '\0' && format[i] != '\0'; i++, j++) {
// 		if (format[i] == '%') {
// 			i++;
// 			if (format[i] == 'd') {
// 				if(aux[j] != '+' && aux[j] != '-' && !isdigit(aux[j]))
// 					return argc;
// 				num = atoi(aux + j);
// 				p = va_arg(args, int *);
// 				*p = num;
// 				while (isdigit(aux[j+1]))
// 					j++;
// 			}
// 			else if (format[i] == 's') {
// 				str = va_arg(args, char *);
// 				strcpy(str, aux+j);
// 				return argc+1;
// 			}
// 			else if (format[i] == '%' && aux[j++] != '%')
// 				return argc;
// 			argc++;
// 		} 
// 		else if (format[i] != aux[j])
// 			return argc;
// 	}

// 	va_end(args);
// 	return argc;
// }

