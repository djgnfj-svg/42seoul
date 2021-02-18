section .text
	global _ft_strcmp

_ft_strcmp:
		push	r10
        mov rax, 0
        mov rbx, 0
		mov		r10, 0				; i = -1
loop:	
		mov		al, BYTE [rdi+r10]	; al = str1[i]
		mov		bl, BYTE [rsi+r10]	; bl = str2[i]
		cmp		al, 0				; if al == 0
		cmp		al, bl				; if al == bl
        je		same				; then loop
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
    