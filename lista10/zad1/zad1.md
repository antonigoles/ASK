Definicje symboli:
- bufp0 (globalny, .data)
- sum (lokalny, .bss)
- incr (lokalny, .text)
- addf (globalny, .text)
- swap (globalny, .text)
- count (lokalny, .bss)
- i te 2 stringi ktore sa pierwszym argumentem prtinf'a (lokalny, .rodata)

Referencje symboli:
- printf (zewnętrzny, nigdzie)
- buf (zewnętrzny, nigdzie)

Wyjście z nm'a:
```bash
antoni:~/Pulpit/ASK/lista10/pliki $ nm swap.o
0000000000000039 T addf
                 U buf
0000000000000000 D bufp0
0000000000000000 b count.0
0000000000000000 t incr
0000000000000000 r .LC0
0000000000000000 r .LC1
                 U printf
0000000000000008 b sum
000000000000006f T swap
``
