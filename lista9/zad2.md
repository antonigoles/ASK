Początkowo funkcja `my_strlen()` zostanie wykonana dokładnie k razy gdzie k to długość stringa stringa stringa s.
Dzieje się tak ponieważ kompilator nie może zbadać semantyki funkcji `my_strlen` i nie wie od czego zależy jej wartość, więc musi wykonać ją za każdym razem kiedy jest potrzebna.

Jeżeli dodamy atrybut `__attribute__ ((pure))`. Kompilator będzie wiedział że funkcja nie ma efektów ubocznych, a jej wynik zależy tylko od argumentów i pamięci globalnej oraz atrybut `__attribute__((leaf))` gwarantuje nam że funkcja nie wywoała żadnej innej funkcji w środku. Skoro nasza funkcja w pętli nie modyfikuje w żaden sposób `s`, kompilator wie że może zapamiętać wartość `my_strlen(s)`


Ciało `my_strlen` z modyfikacjami:
```C
static size_t my_strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}
```

Odziwo godbolt nie chciał zoptymalizować tej funkcji, jedyne co to chciał inlineować
