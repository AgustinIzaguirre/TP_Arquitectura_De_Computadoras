GLOBAL getKey

section .text

getKey:
	cli
	push rbp
	mov rbp,rsp
	mov rax,0h
	loop:
		in al,64h
		and al,1h
		JZ loop
		in al,60h
	movzx rax, al
	mov rsp,rbp
	pop rbp
	sti
	ret