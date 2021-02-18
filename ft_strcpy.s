section .text
    global _ft_strcpy
    
_ft_strcpy:
    mov rax, 0
    jmp solution

solution :
    mov cl, byte [rsi+rax]
    mov byte [rdi+rax], cl
    cmp cl, 0
    je output
    inc rax
    jmp solution

output :
    mov rax, rdi
    ret

