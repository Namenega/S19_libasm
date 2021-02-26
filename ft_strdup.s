	global	_ft_strdup
	extern	_malloc
	extern	_ft_strlen
	extern	_ft_strcpy

_ft_strdup:
	xor		rax, rax		;init rax a 0
	mov		rbx, rdi		;on met le rdi (1er param - char *s) dans rbx
	cmp		rdi, 0			;cmp rdi à 0
	je		_return			;si =, return

_dup:
	call	_ft_strlen			;call strlen(rdi) pr recup la longueur (rax)
	inc		rax					;rax++ pour le \0
	mov		rdi, rax			;rdi = longueur+1
	call	_malloc				;malloc bonne taille (vide) + protect overflow
	cmp		rax, 0				;cmp rax à 0
	je		_return				;si =, return -1
	mov		rdi, rax			;rax dans rdi (futur dest - 1er param)
	mov		rsi, rbx			;rbx = *s de base dans futur src (2eme param)
	call	_ft_strcpy			;strcpy(rdi, rsi)
	ret

_return:
	mov		rax, -1			;return -1
	ret