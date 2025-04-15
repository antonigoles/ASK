/**
    Co robi ta procedura?
    Wygląda na to że szuka indeksu wartości v, w posortowanej tablicy a, na przedziale indeksów od s do e
*/

long puzzle2(long *a, long v, unsigned long s, unsigned long e) {
    // a - %rdi
    // v - %rsi
    // s - %rdx
    // e - %rcx
    // movq %rcx, %rax
    // subq %rdx, %rax
    // shrq %rax
    // addq %rdx, %rax
    long result = ((unsigned long)(e - s) >> 1) + s;

    // cmpq %rdx, %rcx
    // jb .L5
    if (s > e) {
        // .L5
        // movq $-1, %eax; ret
        return -1;
    } else if (v == a[result]) {
        // .L10
        return result;
    } else if (v > a[result]) {
        // .L11
        /**
            leqa -1(%rax), %rcx
            call puzzle2
            ret
        */
        return puzzle2(a, v, s, result - 1);
    } else {
        /**
            leaq 1(%rax), %rdx
            call puzzle2
            ret
        */
        return puzzle2(a, v, result + 1, e);
    }
}
