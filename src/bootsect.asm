[org 0x7c00]
KERNEL_OFFSET equ 0x1000 

    mov [BOOT_DRIVE], dl 
    mov bp, 0x9000
    mov sp, bp

    mov bx, WARN_REAL_MODE 
    call print
    call print_nl

    call load_kernel ; Read KERNEL from DISK
    call switch_to_pm
    jmp $

%include "os/boot/boot_sect_print.asm"
%include "os/boot/boot_sect_print_hex.asm"
%include "os/boot/boot_sect_disk.asm"
%include "os/32bit/gdt.asm"
%include "os/32bit/print.asm"
%include "os/32bit/switch.asm"

[bits 16]
load_kernel:
    mov bx, WARN_LOAD_KERNEL
    call print
    call print_nl

    mov bx, KERNEL_OFFSET 
    mov dh, 31
    mov dl, [BOOT_DRIVE]
    call load_disk
    ret

[bits 32]
BEGIN_PM:
    mov ebx, WARN_PROT_MODE
    call print_str_pm
    call KERNEL_OFFSET 
    jmp $ 

BOOT_DRIVE db 0
WARN_REAL_MODE db "Current: 16bit Real Mode", 0
WARN_PROT_MODE db "Current: 32bit Protected Mode", 0
WARN_LOAD_KERNEL db "Current: Loading kernel into memory", 0
WARN_RETURNED_KERNEL db "Returned from kernel. Error?", 0


times 510 - ($-$$) db 0
dw 0xaa55