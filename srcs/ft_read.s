BITS 64

global _FT_READ
extern __errno_location

section .text
	_FT_READ:
		mov rax, 0x0            ;address de l'appel a read
		syscall                 ; appell systeme qui retourne une valeur dans rax
		cmp rax, 0              ; compare rax a 0
		jl _FT_ERROR_READ       ; si rax < 0, c'est erreur donc envoie _error_read
		ret                     ; sinon retourn rax
	_FT_ERROR_READ:
		neg rax                 ; rend la valeur rax (code errno) positive
		push rbx                ; sauvegarde valeur de rbx dans la pile 
		mov rbx, rax            ;place rax dans rbx
		call __errno_location   ; appel errno location qui renverra pointeur sur la ou doit etre stocke la valeur errno
		mov [rax], rbx          ; place rbx a l'endroit du pointeur
		mov rax, -1             ; met rax a -1
		pop rbx                 ; remet la valeur de rbx comme au debut
		ret                     ; return rax
