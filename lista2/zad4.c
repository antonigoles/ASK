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

uint32_t vec4_sum(uint32_t x, uint32_t y) {
    uint32_t v0 = (x + y) & 0xff;
    uint32_t v1 = ((x & 0xff00) + (y & 0xff00)) & 0xff00;
    uint32_t v2 = ((x & 0xff0000) + (y & 0xff0000)) & 0xff0000;
    uint32_t v3 = ((x & 0xff000000) + (y & 0xff000000)) & 0xff000000;
    return v0 | v1 | v2 | v3;
}

uint32_t vec4_diff(uint32_t x, uint32_t y) {
    uint32_t v0 = (x - y) & 0xff;
    uint32_t v1 = ((x & 0xff00) - (y & 0xff00)) & 0xff00;
    uint32_t v2 = ((x & 0xff0000) - (y & 0xff0000)) & 0xff0000;
    uint32_t v3 = ((x & 0xff000000) - (y & 0xff000000)) & 0xff000000;
    return v0 | v1 | v2 | v3;
}

uint32_t vectorize(uint32_t x3, uint32_t x2, uint32_t x1, uint32_t x0) {
    return (x3 << 24) | (x2 << 16) | (x1 << 8) | (uint32_t)x0;
}

void printVector(uint32_t vec, int nl) {
    printf("{ %d, %d, %d, %d }",
        (vec & 0xff000000) >> 24,
        (vec & 0x00ff0000) >> 16,
        (vec & 0x0000ff00) >> 8,
        vec & 0x000000ff
    );
    if(nl) printf("\n");
}

int main() {
    uint32_t vec1 = vectorize(2, 3, 4, 7);
    uint32_t vec2 = vectorize(8, 255, 1, 255);
    printVector(vec1, 1);
    printVector(vec2, 1);
    printVector(vec4_sum(vec1, vec2), 1);
    printVector(vec4_diff(vec1, vec2), 1);
}
