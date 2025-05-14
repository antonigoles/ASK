Gdyby `long *xp` i `long *yp` wskazywały na to samo miejsce w pamięci:
```C
*xp = 2 * (*xp);
*xp = 0;
*xp = *xp - *xp;
```

To funkcja `swap()` po prostu wyzerowałaby wartość pod adresem `xp`

A z kolei `swap2()`

```C
long x = *xp, long y = *xp;
x = 2 * x; y = x; x = x;
*xp = x;
*yp = y;
```

Faktycznie wykona poprawnego swapa

Aby naprawić funkcje `swap()` należy zamienić jej sygnaturę na

```C
void swap(long *restrict xp, long *restrict yp)
```

Dzięki czemu kompilator będzie wiedział ze `xp` nie może wskazywać na to samo co `yp`
