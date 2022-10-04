BITS 64

global _FT_WRITE
extern __errno_location                   ; externe pour y faire appelle ensuite
section .text
	_FT_WRITE:
		mov rax, 0x1              ;addresse appelle systeme pour write sous linux
		syscall                   ; appel systeme
		cmp rax, 0                ; compare le retour de l'appelle systeme (ds rax) a 0
		jl _RET_ERROR_WRITE       ; si rax < 0 saute a _ret_error_write
		ret 

	_RET_ERROR_WRITE
		neg rax                   ; megatif rax pour le rendre positif (-14 devient 14)
		push rbx                  ; place rbx sur la pile pour conserve sa valeur origin
		mov rbx, rax              ; stock rax dans rbx
		call __errno_location     ; appell focntion _errno_lo... qui retourn l'addresse ou doit etre stocke la valeur de errno
		mov [rax], rbx            ; place rbx (la valeur retourne par write aui est le code erreur errno) dans l'addresse que _errno_locationa renvoye dans rax
		mov rax, -1               ; met rax a -1
		pop rbx                   ; remet la valeur origin de rbx
		ret                       ; return rax
