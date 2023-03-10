section .text
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy
	global _ft_strdup

_ft_strdup:
    call    _ft_strlen 
    inc     rax
    
    push    rdi 
    mov     rdi, rax
    call    _malloc
        cmp rax, 0
        jc error
    pop     rdi
    
    mov     rsi, rdi
    mov     rdi, rax
    call _ft_strcpy  
    ret

error:
    mov rax, 0
    ret