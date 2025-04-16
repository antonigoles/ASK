// stara wersja
// long switch_prob(long x, long n) {
//     n = n - 60;
//     switch ((unsigned int)n) {
//         case 0:
//         case 1:
//             return x * 8;
//         case 4:
//             return x >> 3;
//         case 2:
//             x = (x << 4) - x;
//         case 5:
//             x = x * x;
//         case 3:
//         default:
//             return x + 75;
//     }
// }

// Gdyby jump nie istniał
//
long case1(long x) {
    return x * 8;
}

long case0(long x) {
    return case1(x);
}

long case4(long x) {
    return x >> 3;
}

long cased(long x) {
    return x + 75;
}

long case3(long x) {
    return cased(x);
}

long case5(long x) {
    return case3(x * x);
}

long case2(long x) {
    return case3((x << 4) - x);
}

long switch_prob(long x, long n) {
    n = n - 60;
    long (*cases[7])(long) = {case0, case1, case2, case3, case4, case5, cased};
    long (*c)(long) = n > 6 ? cased : cases[n];
    return c(x);
}
