    .global main
main:
    movq $0x1, %rdi
    movq $0xffffffffffffffff, %rsi
    call _addu

    # Do ładnego wychodzenia z programu na linuxie
    movq $60, %rax    # syscall number for 'exit' is 60
    xor %rdi, %rdi    # return code 0
    syscall           # invoke the syscall

_addu:
    movq $0, %rax
    addq %rdi, %rsi # %rsi = x + y
    sbbq %rax, %rax # jezeli bylo carry to %rax = 0xfff... a jak nie to %rax = 0
    andn %rax, %rsi, %rax # %rax = (NOT %rax) AND %rsi
    ret

# _addu:
#     addq %rdi, %rsi
#     jc .L1
#     mov %rsi, %rax
#     ret
# .L1:
#     movq $0xffffffffffffffff, %rax
#     ret
