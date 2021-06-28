section .text
	global _ft_strcmp

_ft_strcmp:
		push	r10
        mov rax, 0
        mov rbx, 0
		mov		r10, 0
loop:	
		mov		al, BYTE [rdi+r10]
		mov		bl, BYTE [rsi+r10]			
		cmp		al, bl				
        je		same				
		jmp		end

same:
	cmp al, 0
	je 	end
	inc r10
	jmp loop

end:
	pop		r10
	sub		rax, rbx
	ret
    