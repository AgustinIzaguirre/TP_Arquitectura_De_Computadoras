section .text
GLOBAL _int80
%macro pushRegisters 0
	push rbx
	push rcx
	push rdx
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
%endmacro;


%macro popRegisters 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
	pop rdx
	pop rcx
	pop rbx
%endmacro

_int80:
    
    ;push rbp
    ;mov rbp,rsp
	;pushRegisters
	
	;orden de pasaje ABI 64 rdi,rsi,rdx,rcx,r8,r9
	;syscalls rax syscall index,rdi,rsi,rdx,r8,r9
	
	;mov rax,rdi    
	;mov rdi,rsi
	;mov rsi,rdx
	;mov rdx,rcx
	;r8 y r9 ya estan con sus valores
    int 80h
    
	;popRegisters
	;mov rsp,rbp
	;pop rbp
	ret


