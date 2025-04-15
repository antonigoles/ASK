    .global main
main:
    movq $0x1, %rdi
    movq $0xffffffffffffffff, %rsi
    movq $0xf, %rdx
    movq $0xf, %rcx
    call _add128

    # Do ładnego wychodzenia z programu na linuxie
    movq $60, %rax    # syscall number for 'exit' is 60
    xor %rdi, %rdi    # return code 0
    syscall           # invoke the syscall

_add128:
    addq %rsi, %rcx
    adcq %rdi, %rdx
    movq %rcx, %rax
    ret
