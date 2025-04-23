## **Zad 1.**
Załóżmy też że procesor przetwarza potokowo i ma 5 faz (IF, ID, EX, MEM, WB).
Zapis do rejestru odbędzie się w WB, a zczytanie rejestru w ID.
Więc jeżeli rejest X chcemy zczytać w danym cyklu (w fazie ID) to ostatnia aktualizacja tego rejestru (WB)
musi wydarzyć się 3 instrukcje przed tym

Wtedy pierwszy blok kodu

```
1 mov (%rax), %rdi
2 add %rdi, %rsi
3 imul %rcx, %rax, %rdi
4 mov %rsi, (%rcx)
5 and %rcx, %rdi
6 mov %rcx, %rdi
```

trzeba przepisać na

```
1 mov (%rax), %rdi
2 nop
3 nop
4 nop
5 add %rdi, %rsi // %rsi = %rsi + %rdi
6 imul %rcx, %rax, %rdi // %rdi = %rcx * %rax
7 nop
8 nop
9 mov %rsi, (%rcx)
10 and %rcx, %rdi
11 mov %rcx, %rdi
```

A drugi blok

```
1 add %rcx, %rdi
2 mov %rdi, (%rsi)
3 mov 8(%rsi), %rdi
4 add %rdi, %rcx
5 mov %rdi, 16(%rsi)
6 mov %rcx, %rdi
```

Zamieniamy na

```
1 add %rcx, %rdi
2 nop
3 nop
4 nop
5 mov %rdi, (%rsi)
6 mov 8(%rsi), %rdi
7 nop
8 nop
9 nop
10 add %rdi, %rcx
11 mov %rdi, 16(%rsi)
12 nop
13 nop
14 mov %rcx, %rdi
```

## **Zad 2. Usuwanie hazardów**

Dla programu 1:
```
1 mov (%rax), %rdi
2 nop
3 nop
4 nop
5 add %rdi, %rsi // %rsi = %rsi + %rdi
6 imul %rcx, %rax, %rdi // %rdi = %rcx * %rax
7 nop
8 nop
9 mov %rsi, (%rcx)
10 and %rcx, %rdi
11 mov %rcx, %rdi
```

Możemy otrzymać

```
1 mov (%rax), %r8        // r8 = *rax
3 imul %rcx, %rax, %rdi   // rdi = rcx * rax
2 add %r8, %rsi          // rsi += r8
nop
6 mov %rcx, %rdi          // rdi = rcx
5 and %rcx, %rdi          // rdi &= rcx
4 mov %rsi, (%rcx)        // *rcx = rsi
```



Dla programu 2:

```
1 add %rcx, %rdi        // rdi += rcx
2 nop
3 nop
4 nop
5 mov %rdi, (%rsi)      // rsi[0] = rdi
6 mov 8(%rsi), %rdi     // rdi = rsi[1]
7 nop
8 nop
9 nop
10 add %rdi, %rcx       // rcx += rdi
11 mov %rdi, 16(%rsi)   // rsi[2] = rdi
12 nop
13 nop
14 mov %rcx, %rdi       // rdi = rcx
```

Trasnformujemy do:

```
1 add %rcx, %rdi                // rdi += rcx
6 mov 8(%rsi), %rdi             // rdi = rsi[1]
10 add 8(%rsi), %rcx            // rcx += rsi[1]
11 mov 8(%rsi), 16(%rsi)        // rsi[2] = rsi[1]
5 mov %rdi, (%rsi)              // rsi[0] = rdi
14 mov %rcx, %rdi               // rdi = rcx
```

Kroki które zrobiłem: podmieniłem dużą ilość odniesień
do rdi na po prostu wartości rsi[1] i reszta sama się ułatwiła
