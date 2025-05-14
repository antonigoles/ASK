Podstawowa wesja
```C
void compute2(long *a, long *b, long k) {
    long n = 1 << k;
    for (long i = 0; i < n; i++) {
        a[i * n] = a[i] = 0;
    }
    for (long i = 1; i < n; i++) {
        for (long j = 1; j < n; j++) {
            a[j * n + i] = i * j;
        }
    }
    for (long i = 1; i < n; i++) {
        for (long j = 1; j < n; j++) {
            b[i * n + j] = a[i * n + j] + a[(i - 1) * n + (j - 1)];
        }
    }
}
```

Jak powinna wyglądać zoptmymalizowana wersja po krokach:
- Loop interchange
- Loop fusion
- Induction variable elimination

```C
void compute2(long *a, long *b, long k) {
    long n = 1 << k;
    int u0 = 0;
    for (long i = 0; i < n; i++) {
        a[u0] = a[i] = 0;
        u0 += n;
    }
    for (long i = 1; i < n; i++) {
        int in = i * n;
        int im1n = (i - 1) * n;
        int ij = i;
        for (long j = 1; j < n; j++) {
            a[in + j] = ij;
            b[in + j] = a[in + j] + a[im1n + (j - 1)];
            ij += i;
        }
    }
}
```
