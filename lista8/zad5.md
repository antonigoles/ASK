```C
union elem {
  struct {
      long *p;
      long y;
  } e1;
  struct {
      long x;
      union elem *next;
  } e2;
};
```

Tabelka dla e1
| zmienna | alignof | offsetof | sizeof |
| ------- | ------- | -------- | ------ |
| *p      |       0 |        0 |      8 |
| y       |       0 |        8 |      8 |

sizeof(e1) = 8
wymagany alignment dla e1 to 8


Tabelka dla e2
| zmienna | alignof | offsetof | sizeof |
| ------- | ------- | -------- | ------ |
| x       |       0 |        0 |      8 |
| *next   |       0 |        8 |      8 |

sizeof(e1) = 8
wymagany alignment dla e2 to 8

Kod w ASM:

```ASM
proc:
  movq 8(%rdi),%rax
  movq (%rax),%rdx
  movq (%rdx),%rdx
  subq 8(%rax),%rdx
  movq %rdx,(%rdi)
  ret
```

Kod w C:

```C
void proc(union elem *r) {
    union elem *next = r->e2.next;           // rax = *(rdi + 8)    // movq 8(%rdi),%rax
    long *ptr = (long *)next->e2.x;          // rdx = *(rax)        // movq (%rax),%rdx
    long val = *ptr;                         // rdx = *(rdx)        // movq (%rdx),%rdx
    long offset = (long)next->e2.next;       // rdx -= *(rax + 8)   // subq 8(%rax),%rdx
    r->e2.x = val - offset;                  // *(rdi) = rdx        // movq %rdx,(%rdi)
}
```

Kluczowa obserwacja w tłumaczeniu:
1. Bierzemy drugie pole ze struktura przekazanego w argumencie i wrzucamy go do %rax
2. Dereferuncujemy wartośc %rax'a i wpisujemy do %rdx'a, czyli logiczne by było gdyby drugie pole argumentu było pointerem
Wniosek: ta funkcja jest opisana dla strukta z parametrami:
long x;
union elem *next;


Funkcja miałaby też sens dla pierwszego ale najpewniej została opisana dla drugiego
