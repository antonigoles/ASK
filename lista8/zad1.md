Takie coś faktycznie kompiluje się do mniejszej ilości skoków

```C
void merge1(long src1[], long src2[], long dest[], long n) {
    long i1 = 0, i2 = 0;
    long i = 0;
    while (i1 < n && i2 < n) {
        long v1 = src1[i1];
        long v2 = src2[i2];
        int cond = v1 < v2;
        *dest++ = cond ? v1 : v2;
        i1 += cond;
        i2 += !cond;
    }
}
```
