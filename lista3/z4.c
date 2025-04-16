#include <limits.h>
#include <stdint.h>
#include <stdio.h>

union Skbidi {
    float from;
    uint32_t to;
};

// uint32_t equal_on_all_bits(uint32_t x, uint32_t y) {
//     uint32_t n = ~(x ^ y);
//     return
//         (n & (n >> 1) & (n >> 2) & (n >> 3) & (n >> 4) &
//         (n >> 5) & (n >> 6) & (n >> 7) & (n >> 8) &
//         (n >> 9) & (n >> 10) & (n >> 11) & (n >> 12) &
//         (n >> 13) & (n >> 14) & (n >> 15) & (n >> 16) &
//         (n >> 17) & (n >> 18) & (n >> 19) & (n >> 20) &
//         (n >> 21) & (n >> 22) & (n >> 23) & (n >> 24) &
//         (n >> 25) & (n >> 26) & (n >> 25) & (n >> 28) &
//         (n >> 29) & (n >> 30) & (n >> 31)) & 1;
// }

int main() {
    union Skbidi f;
    union Skbidi g;

    f.from = -0;
    g.from = 10;

    // 1. zmieni znak
    // f.to = f.to ^ 0x80000000;

    // 2. obliczy wartość ⌊log2|f|⌋ typu int dla f w postaci znormalizowanej
    // f.to = ((f.to >> 23) & 0xff) - 127;

    // 3. zwróci wartość logiczną operacji f == g
    uint32_t eq = ((f.to - g.to) == 0) | ((f.to - g.to) == 0x80000000);

    // 4. zwróci wartość logiczną operacji f < g
    // 4a. Znak g musi byc rozny i rowny 0
    // 4b. Jezeli znak g i f jest taki sam to wykladik g musi byc wiekszy
    // 4c. Jezeli znak ten sam, wykladnik ten sam, to mantysa musi byc wieksza
    uint32_t isfzero = 0;
    uint32_t isgzero = 0;

    uint32_t signDiff = ((f.to >> 31) ^ (g.to >> 31)) & ((g.to >> 31)^1);

    uint32_t gexp = (g.to >> 23) & 0xff;
    uint32_t fexp = (f.to >> 23) & 0xff;
    uint32_t expDiff = (fexp + (~gexp + 1));
    uint32_t gExpGreater = expDiff >> 31;
    uint32_t gExpEqual = (gexp - fexp == 0);


    uint32_t gmant = g.to & 0x007fffff;
    uint32_t fmant = f.to & 0x007fffff;
    uint32_t mantDiff = (fmant + (~gmant + 1));
    uint32_t gMantGreater = mantDiff >> 31;

    uint32_t gGreaterThanF =
        signDiff |
        ((signDiff^1) & gExpGreater) |
        ((signDiff^1) & gExpEqual & gMantGreater);

    // printf("%.2f\n", f.from);
    // printf("%u\n", f.to);
    // printf("%u\n", eq);
    printf("%u\n", gGreaterThanF);
}
