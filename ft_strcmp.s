bits 64
global ft_strcmp

section .text

ft_strcmp:

.loop:
    mov al, [rdi]
    mov dl, [rsi]
    cmp al, dl
    jne .diff
    cmp al, 0
    je .done
    inc rdi
    inc rsi
    jmp .loop

.diff:
    movzx eax, al
    movzx edx, dl
    sub eax, edx
    ret

.done:
    mov eax, 0
    ret
