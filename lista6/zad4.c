long F(long x);
long M(long x);

long M(long x /* %rdi */) {
    if (x == 0) {
        return x;
    }
    return x - F(M(x - 1));
}

long F(long x /* %rdi */) {
    if (x == 0) {
        return 1;
    }
    return x - M(F(x - 1));
}
