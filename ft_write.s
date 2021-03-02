	global	_ft_write
	extern	___error

_ft_write:
	xor		rax, 1
	mov		rax, 0x2000004	;syscall = 0x2000004 = write
	syscall					;appelle write
	mov		rcx, rax		;rcx = rax
	push	rcx				;garder rax en memoire, au dessus de la pile
	; cmp		rsi, 0			;cmp le buffer (2nd param) à 0
	jc		_ft_error		;si cmp =, go ft_error
	mov		rax, 0x200005c		;check si le fd est bon, syscall = 72 (0x200005c) = fcntl
	mov		rsi, 1			;second param de fcntl doit être = 1
	syscall					;appelle fcntl
	cmp		rax, 0			;cmp rax à 0 (0 = absence d'erreur)
	jne		_ft_error		;si !=, on va dans ft_error
	pop		rax				;on ressort rax
	ret

_ft_error:
	pop		rcx			;on pop rcx
	push	rdx
	mov		rdx, rax	;stock la valeur de rax dans rdx
	call	___error	;renvoie l'adresse de l'erreur
	mov		[rax], rdx	;stock rdx à l'adresse de rax
	mov		rax, -1		;read return -1 si error
	pop		rdx
	ret
