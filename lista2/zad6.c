#include <limits.h>
#include <stdio.h>
#include <stdint.h>

void printbin(uint32_t x) {
    for (int i = 31; i>=0; i-- ) {
        printf("%d", (x >> i) & (uint32_t)1);
    }
}

int32_t _abs(int32_t x) {
    uint32_t isneg = (uint32_t)(x >> 31);
    uint32_t negated = isneg & (-x);
    uint32_t base = (~isneg) & (x);
    return negated | base;
}

int main() {
    int32_t t = 210;
    printf("\n%d\n", _abs(t));
}
