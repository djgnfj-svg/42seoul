section .text
    global _ft_strlen
    
_ft_strlen:
    mov rax, 0
    jmp _loop

_loop:
    cmp BYTE [rdi + rax], 0
    je _loop_end
    inc rax
    jmp _loop
    
_loop_end:
    ret


