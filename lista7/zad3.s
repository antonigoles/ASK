nonsense:
        imulq   24(%rdi), %rsi
        movq    16(%rdi), %r8
        leaq    (%rsi,%rsi,4), %rax
        leaq    (%rsi,%rax,2), %rax
        movq    32(%rdi), %rsi
        movq    (%rdi,%rax,8), %rax
        leaq    (%rsi,%r8,8), %rsi
        addq    $4, %rax
        movq    %rsi, (%rdx)
        movq    %rax, (%rcx)
        ret
