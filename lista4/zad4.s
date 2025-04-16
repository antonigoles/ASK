.globl  main
.globl le2be

main:
    mov $0xFF00, %edi
    call le2be

le2be:
    mov %edi, %eax
    ror $8, %ax
    ror $16, %eax
    ror $8, %ax
    ret
