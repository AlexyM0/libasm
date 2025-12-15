bits 64
global ft_strdup
extern malloc

section .text
ft_strdup:
    push rbx
    mov rbx, rdi
    xor rcx, rcx

.len:
    cmp byte [rdi], 0
    je  .alloc
    inc rdi
    inc rcx
    jmp .len

.alloc:
    inc rcx
    mov rdi, rcx
    call malloc
    test rax, rax
    je   .ret

    mov rdx, rax
    mov rdi, rax
    mov rsi, rbx

.copy:
    mov r8b, [rsi]
    mov [rdi], r8b
    inc rsi
    inc rdi
    test r8b, r8b
    jne  .copy

    mov rax, rdx

.ret:
    pop rbx
    ret

