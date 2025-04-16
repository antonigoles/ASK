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

int32_t sign(int32_t x) {
    int32_t sgn = (uint32_t)x >> 31;
    uint32_t _iszero = (x | (-x)) >> 1;
    return (_iszero) & (-sgn + (sgn^1));
}

int main() {
    printf("%d\n", sign(-5));
    printf("%d\n", sign(-2));
    printf("%d\n", sign(0));
    printf("%d\n", sign(2));
    printf("%d\n", sign(5));
}
