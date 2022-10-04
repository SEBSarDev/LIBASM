BITS 64

global _FT_STRLEN
global _FT_STRLEN_BIS

section .text
	_FT_STRLEN:
		mov rax, -1                 ;depart incrementation i = -1
	_FT_STRLEN_BIS:
		inc rax                     ;incremente i = 0
		cmp byte [rdi + rax], 0     ;compare str[0 + i] a \0
		jne _FT_STRLEN_BIS          ;si different, boucle au debut strlen_bis, sinon
		ret                         ;return rax
