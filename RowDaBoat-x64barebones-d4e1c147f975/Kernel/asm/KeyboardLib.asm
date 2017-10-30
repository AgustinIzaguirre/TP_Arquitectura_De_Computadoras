GLOBAL getKey

section .text

getKey:
	push rbp
	mov rbp,rsp
	mov rax,0h
	loop:
		in al,64h
		and al,1h
		JZ loop
		in al,60h
	mov esp,ebp
	pop rbp
	ret