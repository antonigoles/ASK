Oryginał:
```C
void foobar(long a[], size_t n, long y, long z) {
    for (int i = 0; i < n; i++) {
        long x = y - z;
        long j = 7 * i;
        a[i] = j + x * x;
    }
}
```

Co wypluł kompilator:
```asm
foobar:
        testq   %rsi, %rsi
        je      .L1
        subq    %rcx, %rdx
        leaq    (%rdi,%rsi,8), %rax
        imulq   %rdx, %rdx
.L3:
        movq    %rdx, (%rdi)
        addq    $8, %rdi
        addq    $7, %rdx
        cmpq    %rax, %rdi
        jne     .L3
.L1:
        ret
```

Tłumaczenie na C:
```C
// rdi, rsi, rdx, rcx,
void foobar(long a[], unsigned long n, long y, long z) {
    if (n == 0) return;
    z -= y;
    long result = a[n];
    y *= y;
    while (result != *a) {
        *a = result;
        a++;
        y += 7;
    }
}
```
