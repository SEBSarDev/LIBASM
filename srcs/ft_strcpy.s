BITS 64

global _FT_STRCPY
global _FT_STRCPY_BIS

section .text
	_FT_STRCPY:
	mov rax, -1                      ;increment commence a i = -1
	_FT_STRCPY_BIS:
	inc rax                          ;increment i = 0
	mov dl, byte [rsi + rax]         ; stock src[0+i] dans dl
	mov byte [rdi + rax], dl         ; deplace dl dans dest[0+1]
	cmp byte [rsi + rax], 0          ; compare src[0+i] et \0
	jne _FT_STRCPY_BIS               ; si diffrents, boucle a strcpy_bis
	mov rax, rdi                     ; sinon, place rdi dans rax
	ret                              ;return rax
