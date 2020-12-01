section .text
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy
	global _ft_strdup

//RDI RSI RDX RCX R8 R9
//ft_strdup(const char rdi)
_ft_strdup:
    call    _ft_strlen ;rdi의 문자길이 구함
    inc     rax ;\0값 추가
    
    push    rdi ;rdi의 값을 저장해둠
    mov     rdi, rax ;다음 malloc에 rdi가 매개변수로 간다
    call    _malloc  ; 길이를 넣음 rdi인거지
    pop     rdi ; 넣은값이 나오고 그값의 이름을 rdi라고 지은거임
    
    mov     rsi, rdi ; 처음에 들어온 rdi값이 들어있다
    mov     rdi, rax ; 할당받을 문자열 rdi <- rsi 이런씩으로 처리됨
    call _ft_strcpy  ; rat에 들어감
    ret