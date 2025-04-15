long rec(long x) {
    long y = x + 13;
    if (x > 0) return 2 * rec(x-1);
    return x + 1;
}

int main() {
    int y = 1;
    int x = rec(25);
    return x + y;
}
