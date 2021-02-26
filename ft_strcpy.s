	global	_ft_strcpy

_ft_strcpy:
	xor		rax, rax				;on met rax a 0 -> bitshifting
	xor		rbx, rbx
	cmp		rdi, 0					;1er param = dest
	je		_return					;si cmp =, on va ds 'return'
	cmp		rsi, 0					;2eme param = src
	je		_return

_loop:
	mov		bl, byte [rsi + rax]	; bl = branch with link, on stock b[r+r] (src) dans bl
	mov		byte [rdi + rax], bl	; on met bl dans dst
	cmp		bl, 0
	je		_return
	inc		rax
	jmp		_loop
_return:
	mov		rax, rdi				;on met rdi dans rax (aka valeur de retour)
	ret