// 1. Nie zabezpieczamy w rejestru %r12 w procedurze F (callee-saved)
// 2. Nie "sprzątamy" stosu po wyjściu z M

# źle:
M:
    pushq %rdi
    testq %rdi, %rdi
    je .L2
    leaq -1(%rdi), %rdi
    call M
    movq %rax, %rdi
    call F
    movq (%rsp), %rdi
    subq %rax, %rdi
.L2:
    movq %rdi, %rax
    ret
F:
    testq %rdi, %rdi
    je .L3
    movq %rdi, %r12
    leaq -1(%rdi), %rdi
    call F
    movq %rax, %rdi
    call M
    subq %rax, %r12
    movq %r12, %rax
    ret
.L3:
    movl $1, %eax
    ret

# dobrze:
M:
    pushq %rdi
    testq %rdi, %rdi
    je .L2
    leaq -1(%rdi), %rdi
    call M
    movq %rax, %rdi
    call F
    # movq (%rsp), %rdi # -- niby przywracamy wartość %rdi ale powinniśmy sprzątąć
    subq %rax, %rdi
.L2:
    movq %rdi, %rax
    addq $8, %rsp # -- cofamy stos o długość %rdi
    ret
F:
    pushq %r12 # -- zabezpieczamy %r12
    testq %rdi, %rdi
    je .L3
    movq %rdi, %r12
    leaq -1(%rdi), %rdi
    call F
    movq %rax, %rdi
    call M
    subq %rax, %r12
    movq %r12, %rax
    popq %r12 # --- przywracamy wartość %r12
    ret
.L3:
    movl $1, %eax
    popq %r12 # --- przywracamy wartość %r12
    ret
