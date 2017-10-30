#pragma pack(push);
#pragma pack (1);
#include <stdint.h>

typedef struct {
	uint16_t offset_l;
	uint16_t selector;
	uint8_t cero;
	uint8_t access;
	uint16_t offset_m;
	uint32_t offset_h;
	uint32_t other_cero;

} DESCR_INT;

#pragma pack(pop);

DESCR_INT * idt = (DESCR_INT *) 0;

// void idtLoad() {
// 	_cli();
// 	__asm__("LIDT");
// 	_sti();
// }

// void _cli() {
// 	__asm__("CLI");	
// }


// void _sti() {
// 	__asm__("STI");	
//}

void setup_IDT_entry (int index, uint64_t offset) {
	idt[index].offset_l = offset & 0xFFFF;
	idt[index].selector = 0x08;
	idt[index].cero = 0;
	idt[index].access = 0;
	idt[index].offset_m = (offset >> 16) & 0xFFFF;
	idt[index].offset_h = (offset >> 32) & 0xFFFFFFFF;
	idt[index].other_cero = 0;

}
