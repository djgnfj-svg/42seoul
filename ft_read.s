#include <errno.h>
section .text
    global _ft_read

_ft_read:
	mov r8, rdx
    mov rax, 0x2000003
    __error
	syscall
		jc error//에러이면 flags carry가 바뀜
	jmp end
__errno
error :
	mov rax, -1
	ret

end :
	mov rax, r8
	ret