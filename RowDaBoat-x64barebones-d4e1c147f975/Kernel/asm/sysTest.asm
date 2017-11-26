GLOBAL sysTest

section .text
sysTest:
	push rbp;
	mov rbp,rsp;
	;rax,rdi,rsi,rdx
	lea rdx,[rbp + 8h]
	;mov rax,[rdx];
	;lea rdx,[rbp + 18h]
	;mov rdi,[rdx]
	;lea rdx,[rbp + 20h]
	;mov rsi,[rdx]
	;lea rdx,[rbp + 28h]
	;mov rdx,[rdx]
	;mov rsp, rbp
	;pop rbp
	;int 80h
	ret