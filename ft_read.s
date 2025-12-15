global ft_read
extern __errno_location

section .text

ft_read:
    mov rax, 0
    syscall
    cmp rax, 0
    jl .err
    ret

.err
    neg eax
    mov edx, eax
    call __errno_location
    mov dword [rax], edx
    mov rax, -1
    ret
