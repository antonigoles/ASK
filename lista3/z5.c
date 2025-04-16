#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

union Skbidi {
    float from;
    uint32_t to;
};

uint32_t calcF2I(uint32_t x, int8_t i) {
    int8_t exp = ((x >> 23) & 0xff) >= 127 ? ((x >> 23) & 0xff) - 127 : ((x >> 23) & 0xff) - 127;
    // printf("%d\n", exp);
    if (i>0 && exp>0 || i<0 && exp<0) {
        // same signs, might overflow
        int8_t res = exp+i;
        if (i>0) {
            if (res<exp) return 0x7F800000;
        } else {
            if (res>exp) return 0xFF800000;
        }
    };
    printf("Old exp: %d\n", exp);
    exp += i;
    uint32_t convExp = (uint32_t)exp + 127;
    printf("New exp: %d\n", convExp);

    return (x & 0x800fffff) | ((uint32_t)convExp << 23);
}

int main() {
    union Skbidi f;
    f.from = 2;
    f.to = calcF2I(f.to, 8);
    printf("%.2f\n", f.from);
}
