section .text
    global _ft_strcpy
    
//RDI RSI RDX RCX R8 R9
_ft_strcpy:
    mov rax, 0
    jmp solustion

// ft_strcpy() rdi = dst, rsi = src)
solusion :
    mov cl, byte [rsi+rax]
    mov byte [rdi+rax], cl
    cmp cl, 0
    je output
    inc rax
    jmp solusion

output :
    mov rat, rdi    ;리턴값은 맨압의 주소값
    ret

