// GODBOLT DLA x86-64 clanga 19.1.0
// z parametrami -O2 -masm=att i output intel asm syntax na off
// kompiluje do dokładnie ASM z treści zadania


// n - %rdi, p - %rsi
long pointless(long n, long *p) {
    // pushq r14 - callee-saved reigster
    // pushq rbx - callee-saved reigster
    // pushq %rax - odkładamy raxa na stos dla zachowania podzielności przez 16 stosu
    // movq %rsi, %r14 - wsadź drugi argument do %r14
    // movq %rdi, %rbx - wsadź pierwszy argument do %rbx
    // testq %rdi, %rdi
    // jle .L1
    // .L1
    long result;
    if (n <= 0) {
        // xorl %eax, %eax - wyzeruj %eax'a
        result = 0;
    } else {
        /**
            wszystko od linijki 9 do 13

            leaq (%rbx, %rbx), %rdi
            movq %rsp, %rsi
            callq pointless
            addq (%rsp), %rax
        */
        result += pointless(2 * n, &result);
    }
    /**
        addq %rax, %rbx
        movq %rbx, (%r14)
    */
    *p = n + result;

    // Czyszczenie stosu
    /**
        addq $8, %rsp - cofnij granice stosu o 8 do tyłu aka usuń rax'a ze stosu ale nie wpisuj go do rejestru %rax
        popq %rbx - przywróć rbx'a
        popq %r14 - przywróć r14
    */
    return result;
}
