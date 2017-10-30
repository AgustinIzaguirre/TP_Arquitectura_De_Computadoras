static tick = 0;

void timerTickHandler() 
{
	tick++;
	ncPrintDec(tick);
}

void setUPTimerTickHandler() {
	__asm__("CLI");
	setup_IDT_entry (0x20, (uint64_t)&timerTickHandler);
	picMasterMask(0xFE);
	picSlaveMask(0xFF);
	__asm__("STI");
}