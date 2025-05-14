```C
/* mismatch-a.c */
void p2(void);

int main(void) {
    p2();
    return 0;
}
```

```C
/* mismatch-b.c */
#include <stdio.h>

char main;

void p2(void) {
    main = 'a';
    printf("0x%x\n", main);
}
```


1. Czemu tak się dzieje że program nie zgłasza błędów?
- Bo linker jest "głupi" (cytując Cahira) i typy, a nawet rozmiary typów go nie obchodzą. On po prostu widzi symbol i informacje jak ma czytać dane pod tym symbolem

2. Skąd pochodzi wydrukowana wartość?
- To jest po prostu wskaźnik na funkcje main

3. Czym się różni symbol silny od słabego?
- Symbole ze zdefiniowaną wartością są silne, a z kolei te bez zdefiniowanej wartości są słabe. Dodatkowo te z keywordem "extern" są bardzo słabe.
Zasada jest taka że konsolidator do zdefiniowania symbolu, używa jego "najsilniejszego" wystąpienia.

4. Co by się stało, gdybyśmy w funkcji p2 przypisali wartość
pod zmienną main?
- Dostalibyśmy `Naruszenie ochrony pamięci (zrzut pamięci)`.
Dlaczego? Bo `main` znajduje się w pamięci read only

5. Co by się zmieniło gdybyśmy w pliku mismatch-b.c zainicjowali zmienną main w
miejscu jej definicji?
- Konsolidator by się popłakał : ( bo mielibyśmy 2 silne symbole o takiej samej nazwie
```bash
antoni:~/Pulpit/ASK/lista10/pliki $ make mismatch
gcc -fno-pie -fno-asynchronous-unwind-tables -Og -Wall -Wno-main -fcommon -c -o mismatch-b.o mismatch-b.c
strip -g mismatch-b.o
gcc -static -static -o mismatch mismatch-a.o mismatch-b.o
/usr/bin/ld: mismatch-b.o:(.data+0x0): multiple definition of `main'; mismatch-a.o:(.text+0x0): first defined here
collect2: error: ld returned 1 exit status
make: *** [Makefile:30: mismatch] Błąd 1
```

6.  Czemu dobrym pomysłem jest przekazywanie opcji -fno-common do kompilatora?
- Dzięki temu linker nie będzie wybierał "dowolnie", którego słabego symbolu ma użyć, tylko nakrzyczy na nas jeżeli użyjemy w różncyh plikach w scopie globalnym tej samej nazwy symbolu - o ile nie użyjemy extern, ale wtedy jasno widać, który jest który

w skrócie
- zwiększa bezpieczeństwo kompilacji
- zapobiega trudnym błędom linkera
