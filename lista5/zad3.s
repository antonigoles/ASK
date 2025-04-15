    .global main
main:
    movq $0x1, %rdi
    movq $0xffffffffffffffff, %rsi
    call _cmp

    # Do ładnego wychodzenia z programu na linuxie
    movq $60, %rax    # syscall number for 'exit' is 60
    xor %rdi, %rdi    # return code 0
    syscall           # invoke the syscall

# proste i głupie
_cmp:
    # x, y
    cmp %rdi, %rsi
    jl .L1
    jg .L2
    je .L3
.L1:
    movq $0xffffffffffffffff, %rax
    ret
.L2:
    movq $0x1, %rax
    ret
.L3:
    movq $0x0, %rax
    ret
