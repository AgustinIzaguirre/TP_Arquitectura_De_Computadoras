#include <stdint.h>
#include <videoDriver.h>

uint64_t sys_write(unsigned int fd, const char* buffer, uint64_t count);

uint64_t systemCallDispatcher(uint64_t rax, uint64_t rdi, uint64_t rsi, uint64_t rdx) {

		switch(rax) {
			// case 0:
			// 	return sys_read(rdi,rsi,rdx);
			case 1:
				return sys_write(rdi,rsi,rdx);
		}
		return 0;
}

uint64_t sys_write(unsigned int fd, const char* buffer, uint64_t count) {
	int i = 0;
	while(i<count){
		draw_char(buffer[i]);
		i++;
	}
	return count;
}

// uint64_t sys_read(unsigned int fd, const char* buffer, uint64_t count) {
// 	int i = 0;
// 	while(i<count){
// 		draw_char(buffer[i]);
// 		i++;
// 	}
// 	return count;
// }