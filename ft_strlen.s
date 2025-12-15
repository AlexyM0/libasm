bits 64
global ft_strlen

section .text

ft_strlen:
    mov rax, 0

.loop:
    cmp byte [rdi], 0
    je .done
    inc rax
    inc rdi
    jmp .loop

.done:
    ret
