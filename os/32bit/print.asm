[bits 32]

VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f 

print_str_pm:
    pusha
    mov edx, VIDEO_MEMORY

ps_pm_loop:
    mov al, [ebx]
    mov ah, WHITE_ON_BLACK

    cmp al, 0 
    je print_str_pm_done

    mov [edx], ax
    add ebx, 1 
    add edx, 2 

    jmp ps_pm_loop

print_str_pm_done:
    popa
    ret