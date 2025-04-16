#include <limits.h>
#include <stdio.h>
#include <stdint.h>

void printbin(uint32_t x, short nl) {
    for (int i = 31; i>=0; i-- ) {
        printf("%d", (x >> i) & (uint32_t)1);
    }
    if (nl) {
        printf("\n");
    }
}

int32_t _abs(int32_t x) {
    uint32_t isneg = (uint32_t)(x >> 31);
    uint32_t negated = isneg & (-x);
    uint32_t base = (~isneg) & (x);
    return negated | base;
}

int32_t threefourths(int32_t x) {
    uint32_t isneg = (uint32_t)(x >> 31);
    int32_t ax = _abs(x);
    return isneg & (-((ax >> 1) + (ax >> 2))) | ~isneg & (((ax >> 1) + (ax >> 2)));
}

int main() {
    int32_t t = 10;
    printf("%d\n", threefourths(t));
}
