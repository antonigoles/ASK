Struktura:
```C
struct node {
    char id[2];
    int (*hashfn)(char *);
    short flags;
    union {
        struct {
            short n_key;
            int n_data[2];
            unsigned char n_type;
        } s;
        unsigned l_value[2];
    } u;
};
```

Struct zagnieżdżony `s`
| zmienna | alignof | offsetof | sizeof |
| ------- | ------- | -------- | ------ |
| n_key   |       2 |        0 |      2 |
| n_data  |       0 |        4 |      8 |
| n_type  |       0 |       12 |      1 |

sizeof(s) = 16 (po zaalingownaiu do najbliższej podzielniej przez 4)
alignment dla tej struktury to 4

Unia zagnieżdżona `u`
| zmienna | alignof | offsetof | sizeof |
| ------- | ------- | -------- | ------ |
| s       |       0 |        0 |     16 |
| l_value |       0 |       16 |      8 |

sizeof(u) = 16 (po zaalingownaiu do najbliższej podzielniej przez 4 i wybraniu maksymalnego elementu)
alignment dla tej struktury to 4


Pierwsza wersja Node
| zmienna | alignof | offsetof | sizeof |
| ------- | ------- | -------- | ------ |
| id      |       7 |        0 |      1 |
| hashfn  |       0 |        8 |      8 |
| flags   |       2 |       16 |      2 |
| u       |       4 |       20 |     16 |

alignment dla tej struktury to 8
sizeof(Node) = 40 (po zaalingownaiu do najbliższej podzielniej przez 8)


Optymalizacja:
Sortujmy względem wymaganego alignmentu

```C
struct node {
    int (*hashfn)(char *);
    union {
        struct {
            int n_data[2];
            short n_key;
            unsigned char n_type;
        } s;
        unsigned l_value[2];
    } u;
    short flags;
    char id[2];
};
```

Struktura zagnieżdżona `s`
| zmienna | alignof | offsetof | sizeof |
| ------- | ------- | -------- | ------ |
| n_data  |       0 |        0 |      8 |
| n_key   |       0 |        8 |      2 |
| n_type  |       0 |       10 |      1 |

sizeof(s) = 12 (po zaalingownaiu do najbliższej podzielniej przez 4)
alignment dla tej struktury to 4

Unia zagnieżdżona `u`
| zmienna | alignof | offsetof | sizeof |
| ------- | ------- | -------- | ------ |
| s       |       4 |        0 |     12 |
| l_value |       0 |        0 |      8 |

sizeof(u) = 12 (po zaalingownaiu do najbliższej podzielniej przez 4)
alignment dla tej struktury to 4

Optymalna wersja Node
| zmienna | alignof | offsetof | sizeof |
| ------- | ------- | -------- | ------ |
| hashfn  |       0 |        0 |      8 |
| u       |       0 |        8 |     12 |
| flags   |       0 |       20 |      2 |
| id      |       1 |       22 |      1 |

sizeof(Node) = 24 (po zaalingownaiu do najbliższej podzielniej przez 4)
alignment Node to 4

woohoo duża oszczędność
