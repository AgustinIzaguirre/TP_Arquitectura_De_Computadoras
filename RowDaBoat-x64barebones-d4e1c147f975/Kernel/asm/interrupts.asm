
GLOBAL _cli
GLOBAL _sti
GLOBAL picMasterMask
GLOBAL picSlaveMask
GLOBAL haltcpu
GLOBAL _hlt

GLOBAL _irq00Handler
GLOBAL _irq01Handler
GLOBAL _irq02Handler
GLOBAL _irq03Handler
GLOBAL _irq04Handler
GLOBAL _irq05Handler

GLOBAL _systemCallsHandler

GLOBAL _exception0Handler

EXTERN irqDispatcher
EXTERN exceptionDispatcher
EXTERN systemCallDispatcher

SECTION .text

%macro pushState 0
	push rax
	push rbx
	push rcx
	push rdx
	push rbp
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
%endmacro

%macro popState 0
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
	pop rbp
	pop rdx
	pop rcx
	pop rbx
	pop rax
%endmacro

%macro irqHandlerMaster 1
	pushState

	mov rdi, %1 ; pasaje de parametro
	call irqDispatcher

	; signal pic EOI (End of Interrupt)
	mov al, 20h
	out 20h, al

	popState
	iretq
%endmacro


;Fuente:http://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
%macro systemCallHandler 0
	push rbp
	push rsp
	push rbx
	push r12
	push r13
	push r15
	
	;orden de pasaje ABI 64 rdi,rsi,rdx,rcx
	;syscalls rax syscall index,rdi,rsi,rdx
	mov rbx, rdi ;preservo rdi
	mov rdi, rax ; pasaje del primer parametro
	
	mov r12, rsi ;preservo rsi
	mov rsi, rbx ;pasaje del segundo parametro
	
	mov r15, rdx ;preservo rdx
	mov rdx,r12 ;pasaje del tercer parametro

	mov rcx, r15 ;pasaje del cuarto parametro
	call systemCallDispatcher

	pop r15
	pop r13
	pop r12
	pop rbx
	pop rsp
	pop rbp
	iretq
%endmacro


%macro exceptionHandler 1
	pushState

	mov rdi, %1 ; pasaje de parametro
	call exceptionDispatcher

	popState
	iretq
%endmacro


_hlt:
	sti
	hlt
	ret

_cli:
	cli
	ret


_sti:
	sti
	ret

picMasterMask:
	push rbp
    mov rbp, rsp
    mov ax, di
    out	21h,al
    pop rbp
    retn

picSlaveMask:
	push    rbp
    mov     rbp, rsp
    mov     ax, di  ; ax = mascara de 16 bits
    out	0A1h,al
    pop     rbp
    retn


;8254 Timer (Timer Tick)
_irq00Handler:
	irqHandlerMaster 0

;Keyboard
_irq01Handler:
	irqHandlerMaster 1

;Cascade pic never called
_irq02Handler:
	irqHandlerMaster 2

;Serial Port 2 and 4
_irq03Handler:
	irqHandlerMaster 3

;Serial Port 1 and 3
_irq04Handler:
	irqHandlerMaster 4

;USB
_irq05Handler:
	irqHandlerMaster 5

;Systems calls handler
_systemCallsHandler:
	systemCallHandler


;Zero Division Exception
_exception0Handler:
	exceptionHandler 0

haltcpu:
	cli
	hlt
	ret



SECTION .bss
	aux resq 1