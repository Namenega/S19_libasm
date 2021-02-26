	global	_ft_strcmp

_ft_strcmp:
	mov		rax, -1		;on set rax a -1
	xor		rbx, rbx	;on set rbx a 0
	xor		rcx, rcx	;on set rcx a 0

_loop:
	inc		rax;					;on incremente rax
	mov		bl, byte [rdi + rax]	;on copie les 8 derniers bits dans bl ((branch with link)
									;bl = 8 derniers bits de rbx
	mov		cl, byte [rsi + rax]	;on copie les 8 derniers bits dans cl (branch with link 2)
									;cl = 8 derniers bits de rcx
	cmp		bl, 0					;on compare bl a 0
	je		_compare				;si =, on va ds _compare
	cmp		cl, 0					;on compare cl a 0
	je		_compare				;si =, on va ds _compare
	cmp		bl, cl					;on compare bl et cl
	jne		_compare				;si !=, on va ds _compare
	jmp		_loop					;on recommence la boucle

_compare:
	mov		rax, rbx	;on met rbx (donc bl) dans rax
	sub		rax, rcx	;on soustrait rcx a rax (donc rbx)
	cmp		rax, 0		;on compare cette difference a 0
	jg		_sup		;si rax > 0, on jump dans _sup
	jl		_inf		;si rax < 0, on jump dans _inf
	ret

_sup:
	mov		rax, 1		;return 1
	ret

_inf:
	mov		rax, -1		;return -1
	ret