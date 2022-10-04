BITS 64

global _FT_STRDUP
extern malloc
extern _FT_STRCPY
extern _FT_STRLEN

section .text
	_FT_STRDUP:
		call _FT_STRLEN        ;envoie a strlen avec le meme rdi(1er argument)
		inc rax                ; ajoute 1 a rax pou le \0
		push rdi               ; sauvegarde dans la pile rdi
		mov rdi, rax           ; place rax en rdi (1er arg)
		call malloc            ; envoie a malloc avec rdi enn arg, donc res de strlen+1
		cmp rax, 0             ; compare le retour de malloc a 0
		je _FT_ERROR_STRDUP    ; si c'est egale a 0, envoie a error
		push rax               ; sinon sauvegarde resultat dans pile
		pop rdi                ; retire la derniere valeur de la pile (celle qu'on vient de mettre) et met ds rdi (1er arg)
		pop rsi                ; on retire le dernier element de la pile (donc le premier qu'on a mis, rdi) et met dans rsi (2e arg)
		call _FT_STRCPY        ; appelle strcpy avec &ere argument rdi et deuxieme rsi
		ret		       ; return rax, c'est a dire le pointeur renvoye par malloc qu'on a envoye en 1e argument de strcpy

	_FT_ERROR_STRDUP:
		pop rdi                ; retire rdi qu'on a push
		ret                    ; return rax qui contient la valeur renvoye par malloc, un ptr null


; ----------------------------------------------------------------------------------------------------
; autre maniere de faire, sans pousser sur pile mais en utilisant un temp tbx pour stocker les valeurs
;section .text
;	_FT_STRDUP:
;		push rbx              ;sauvegarde la valeur de rbx dans pile
;		call _FT_STRLEN       ; appel strlen avec rdi en arg
;		inc rax               ; augmente d'un pour \0
;		mov rbx, rdi          ; stock rdi dans rbx
;		mov rdi, rax          ; met rax dans rdi 1er argument
;		call malloc           ; appeler malloc avec rdi
;		cmp rax, 0            ; compare retour malloc a 0
;		je _FT_ERROR_STRDUP   ; si egale a 0 saute a _error_strdup
;		mov rsi, rbx          ; met la valeur rbx dans 2e arg rsi
;		mov rdi, rax          ; met rax (ptr de malloc) dans &er argument rdi
;		call _FT_STRCPY       ; appelle strcpy avec rdi et rsi en arg
;		pop rbx               ; enleve de la pile rbx pour lui redonner sa valeur originale
;		ret                   ; return rax (ptr)
;
;	_FT_ERROR_STRDUP:
;		pop rbx               ; reprend la valeur conserve de rbx
;		ret                   ; return rax (ptr null renvoye par malloc)
