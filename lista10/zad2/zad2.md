Dumpy wyników wszystkich komend

## Zawartość .strtab

```bash
antoni:~/Pulpit/ASK/lista10/pliki $ readelf -p .strtab swap.o
String dump of section '.strtab':
  [     1]  .LC1
  [     6]  incr
  [     b]  count.0
  [    13]  .LC0
  [    18]  sum
  [    1c]  printf
  [    23]  addf
  [    28]  swap
  [    2d]  bufp0
  [    33]  buf
```

Co przechowuje? Liste wszystkich symboli w pliku

## Zawartość .shstrtab

```bash
antoni:~/Pulpit/ASK/lista10/pliki $ readelf -p .shstrtab swap.o
String dump of section '.shstrtab':
  [     1]  .symtab
  [     9]  .strtab
  [    11]  .shstrtab
  [    1b]  .rela.text
  [    26]  .data
  [    2c]  .bss
  [    31]  .rodata.str1.1
  [    40]  .rela.data.rel
  [    4f]  .rodata.cst8
  [    5c]  .comment
  [    65]  .note.GNU-stack
  [    75]  .note.gnu.property
```

Co przechowuje? Liste wszystkich sekcji w pliku

## Sekcje i ich numery

```bash
antoni:~/Pulpit/ASK/lista10/pliki $ readelf -S swap.o
There are 15 section headers, starting at offset 0x488:

Section Headers:
  [Nr] Name              Type             Address           Offset
       Size              EntSize          Flags  Link  Info  Align
  [ 0]                   NULL             0000000000000000  00000000
       0000000000000000  0000000000000000           0     0     0
  [ 1] .text             PROGBITS         0000000000000000  00000040
       00000000000000a1  0000000000000000  AX       0     0     1
  [ 2] .rela.text        RELA             0000000000000000  000002b0
       0000000000000138  0000000000000018   I      12     1     8
  [ 3] .data             PROGBITS         0000000000000000  000000e1
       0000000000000000  0000000000000000  WA       0     0     1
  [ 4] .bss              NOBITS           0000000000000000  000000e8
       0000000000000010  0000000000000000  WA       0     0     8
  [ 5] .rodata.str1.1    PROGBITS         0000000000000000  000000e8
       000000000000000a  0000000000000001 AMS       0     0     1
  [ 6] .data.rel         PROGBITS         0000000000000000  000000f8
       0000000000000008  0000000000000000  WA       0     0     8
  [ 7] .rela.data.rel    RELA             0000000000000000  000003e8
       0000000000000018  0000000000000018   I      12     6     8
  [ 8] .rodata.cst8      PROGBITS         0000000000000000  00000100
       0000000000000008  0000000000000008  AM       0     0     8
  [ 9] .comment          PROGBITS         0000000000000000  00000108
       000000000000002c  0000000000000001  MS       0     0     1
  [10] .note.GNU-stack   PROGBITS         0000000000000000  00000134
       0000000000000000  0000000000000000           0     0     1
  [11] .note.gnu.pr[...] NOTE             0000000000000000  00000138
       0000000000000020  0000000000000000   A       0     0     8
  [12] .symtab           SYMTAB           0000000000000000  00000158
       0000000000000120  0000000000000018          13     7     8
  [13] .strtab           STRTAB           0000000000000000  00000278
       0000000000000037  0000000000000000           0     0     1
  [14] .shstrtab         STRTAB           0000000000000000  00000400
       0000000000000088  0000000000000000           0     0     1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  D (mbind), l (large), p (processor specific)
```

## Symbole i informacje o nich

```bash
antoni:~/Pulpit/ASK/lista10/pliki $ readelf -s swap.o
Symbol table '.symtab' contains 12 entries:
   Num:    Value          Size Type    Bind   Vis      Ndx Name
     0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND
     1: 0000000000000000     0 SECTION LOCAL  DEFAULT    4 .bss
     2: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT    5 .LC1
     3: 0000000000000000    57 FUNC    LOCAL  DEFAULT    1 incr
     4: 0000000000000000     4 OBJECT  LOCAL  DEFAULT    4 count.0
     5: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT    8 .LC0
     6: 0000000000000008     8 OBJECT  LOCAL  DEFAULT    4 sum
     7: 0000000000000000     0 NOTYPE  GLOBAL DEFAULT  UND printf
     8: 0000000000000039    54 FUNC    GLOBAL DEFAULT    1 addf
     9: 000000000000006f    50 FUNC    GLOBAL DEFAULT    1 swap
    10: 0000000000000000     8 OBJECT  GLOBAL DEFAULT    6 bufp0
    11: 0000000000000000     0 NOTYPE  GLOBAL DEFAULT  UND buf
```
Ndx - numer sekcji
Value - ZALEŻY*
Size - rozmiar symbolu (wskaźnika)


## Definicja `Elf64_Sym` wg. Figure 4-18: Symbol Table Entry (https://www.sco.com/developers/gabi/latest/ch4.symtab.html)


```C
typedef struct {
    Elf64_Word	st_name; // nazwa symbolu
    unsigned char	st_info; // to pole definiuje typ symbolu
    unsigned char	st_other; // w dzisiejszych czasach używany do przechowywania widoczności symbolu (globalny, lokalny, zewnętrzny)
    Elf64_Half	st_shndx; // Index sekcji w tabeli sekcji, do której nalezy ten symbol
    Elf64_Addr	st_value; // ZALEŻY*
    Elf64_Xword	st_size; // rozmiar symbolu
} Elf64_Sym;
```

ZALEŻY*:
`st_value` przechowuje:
- W plikach relokacyjnych, jeżeli symbol jest typu "COMMON" to przechowuje tu informacje o alignmencie
-  W plikach relokacyjnych, normalnie przechowuje informacje o offsecie od początku sekcji, w której się znajduje
- W exec'ach i bibliotekach dzielonych (.so) przechowywuje informacje o adresie wirtualnym symbolu
