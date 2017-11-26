#include <test.h>
#include <stdlib.h>

void test(int id) {
	switch(id) {
		case ZERODIVISION: zeroDivisionTest();
				break;
		case INVALIDOPCODE: invalidOpCodeTest();
				break;
		case OVERFLOW: overflowTest();
				break;
		case GENERALPROTECTIONFAULT: generalProtectionFaultTest();
	}

}

void zeroDivisionTest() {
	int i = 10/0;
}

void generalProtectionFaultTest() {
	int * p = 0;
	*p = 10;
}

