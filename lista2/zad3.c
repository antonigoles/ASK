#include <limits.h>
#include <stdio.h>
#include <stdint.h>

uint32_t proc(int32_t x, int32_t y) {
    int32_t s = x + y;
    return (uint32_t)(((x ^ s) & (y ^ s)) & 0x80000000) >> 31;
}

int main() {
    int32_t t = 0x80000000;
    printf("%d, %d\n", t+t, proc(t, t));
    printf("%d, %d\n", 4, proc(2, 3));
}
