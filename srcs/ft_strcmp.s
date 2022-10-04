BITS 64

global _FT_STRCMP

section .text
	_FT_STRCMP:
	push rbx;                        ; place rbx dans pile pour conserve s valeur d'origin
	mov rbx, -1                      ;debut incrementation, i = -1

	_FT_STRCMP_BIS:
	inc rbx                          ; increment i = 0
	mov dl, byte [rsi + rbx]         ; stock s2[0 + i] dans dl
	cmp byte [rdi + rbx], dl         ; compare s1[0 + i] et dl (donc s2[0 + i])
	je _FT_STRCMP_CONTINUE           ; s'ils sont egaux, saute a strcmp_continue
	jne _FT_STRCMP_END               ; sinon saute a strcmp_end

	_FT_STRCMP_CONTINUE:
	cmp byte [rdi + rbx], 0          ; compare s1[0 +i] et \0
	je _FT_STRCMP_END                ; si egaux, saute a strcmp_end
	jne _FT_STRCMP_BIS               ; sinon, boucle et retourne a strcmp_bis
	
	_FT_STRCMP_END:
	xor rax, rax                     ; initialise rax a 0
	cmp byte [rdi + rbx], dl         ; compare s1[0 +i] et s2[0+i] (dans dl)
	jae _FT_POSITIF                  ; si s1[0+i] >= s2[0+i], saute a ft_positif
	jb _FT_NEGATIF                   ; si s1[0+i] < s2[0+i], saute a ft_negatif
	
	_FT_POSITIF:
	mov al, byte [rdi + rbx]         ; stock s1[0+i] dans al (qui est 8 bits low de rax)
	sub al, byte [rsi + rbx]         ; stock s1[0+i](al) - s2[0+i] dans al
	jmp _FT_STRCMP_CLOSE             ; saute a strcmp_close
	
	_FT_NEGATIF:
	mov al, byte [rsi + rbx]         ; stock s2[0+i] dans al
	sub al, byte [rdi + rbx]         ; stock s2[0+i](al) - s1[0+i] dans al
	neg eax                          ; met en negatif eax (32 bits de rax, al ne pas neg)
	jmp _FT_STRCMP_CLOSE             ; saute a strcmp_close
	
	_FT_STRCMP_CLOSE:
	pop rbx                          ; remet la valeur de base de rbx dans rbx
	ret                              ; return rax
