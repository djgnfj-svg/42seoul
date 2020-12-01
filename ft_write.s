section .text
    global _ft_write

//RDI RSI RDX RCX R8 R9
_ft_write:
			mov r8, rdx
			mov		rax, 0x2000004
			syscall
				jc error//에러이면 flags carry가 바뀜
			jmp end

error :
	mov rax, -1
	ret

end :
	mov rax, r8
	ret
