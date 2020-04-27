;; SIMPLE LITTLE BOOTLOADER

global start
extern kmain ; change the name if you do not want to use kmain.
MAGIC equ 0x1badb002 ; boots
FLAGS equ 0x3
CHECKSUM equ -(MAGIC + FLAGS)




section .text
align 4
dd MAGIC    
dd FLAGS
dd CHECKSUM


start:
call kmain ; change the name if you do not want to use kmain.
cli


quit:
hlt
jmp quit