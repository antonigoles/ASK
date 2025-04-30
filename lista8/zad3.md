Najłatwiejsza obserwacja na start: 8RST = 3640 => RST = 455

Translacja stopniowa kodu:

```asm
store_elem:
  leaq (%rsi,%rsi,2),%rax
  leaq (%rsi,%rax,4),%rax
  movq %rdi,%rsi
  salq $6,%rsi
  addq %rsi,%rdi
  addq %rax,%rdi
  addq %rdi,%rdx
  movq A(,%rdx,8),%rax
  movq %rax,(%rcx)
  movq $3640,%rax
  ret
```

na

```C
// rdi, rsi, rdx, rcx
store_elemt(long i, long j, long k, long *dest) {
  p = 13 * j;
  j = i;
  j = j * 64;
  // i = i + j + p;
  k = k + i + (i * 64) + (13 * j);
  // k = k + (13 * j) + (i * 65) );
  *dest = A[k]
  return 3640;
}
```

Accesowanie można przetlumaczyć na jednowymiarową tablice przy użyciu wzoru
```C
A[i][j][k] = A[T*S*i + T*j + k]
```

więc jeżeli dostaliśmy
```C
A[(i * 65) + (13*i) + k]
```

czyli
```C
A[(i * 13 * 5) + (13*i) + k]
```

to znaczy że S = 5, T = 13, R = (3640/8)/(5 * 13) = 7
