section .text

GLOBAL generalProtectionFaultTest

generalProtectionFaultTest:
	mov cr6,eax
	ret
