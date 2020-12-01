section .text
    global _ft_strcmp
//ft_strcmp(rdi, rsi)
_ft_strcmp:
    push r10
    mov r10, 0
    jmp solusion

intcrement:
    inc r10
solusion :
    mov     al, byte[rdi+r10]
    mov     bl, byte[rsi+r10]
    cmp     al,0
    je      output
    cmp     bl,0
    je      output
    cmp     al, bl
    je      increment
    jmp     output
    
output:
    pop     r10
    sub     rax, rbx
    ret