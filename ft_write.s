bits 64
global ft_write
extern __errno_location

section .text

ft_write:
    mov rax, 1
    syscall
    cmp rax, 0
    jl .err
    ret

.err:
    neg eax
    mov edx, eax
    call __errno_location
    mov dword [rax], edx
    mov rax, -1
    ret