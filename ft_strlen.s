	global	_ft_strlen
_ft_strlen:
	mov		rax, -1	; la variable 'rax' = -1	-> rax = valeur de retour.

_loop:
	inc		rax		; incremente rax de 1
	cmp		byte [rdi + rax], 0 ; byte [xxx], on modifie les 8 derniers bits
								; de l'adresse de [rdi + rax]
								; rdi = 1er param
	jne		_loop
	ret
