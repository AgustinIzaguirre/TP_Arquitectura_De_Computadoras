GLOBAL callWrite

section .text

callWrite:
	mov rax,1h
	mov rdi,0
	mov rsi, buffer
	movzx rdx, byte [count]
	int 80h
	ret

section .data
	buffer db "hola como va",0
	count db 5