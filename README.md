

RDI RSI RDX RCX R8 R9


ft_strdup(const char rdi)

ft_strlen의 값이 rax에 들어감 1
rax 숫자 하나 증가시킴 null을 위해 2
rdi 값을 스택에 저장
rdi 에 rax(할당받아야하는 총 길이를 rdi에 전달) 4
반환값은 rax에 전달됨 5
정상적으로 할당이 된다면 rdi의 값을 다시 rdi에 전달

rsi 값에 rdi 이동 (rsi인 이유는 카피에 넣어야 하기 때문에)
rdi 에 할당받은메모리를 이동
rsi 에는 복사해야되는 문자열이 들어가 있고 rdi에는 할당된 공간이 있음
rdi 에 rsi의 값은 하나씩 넣어줌 (cpy에서)