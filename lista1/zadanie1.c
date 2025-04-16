#include <stdio.h>
#include <stdint.h>

void printBin(uint32_t n) {
    uint32_t i = 32;
    while (i > 0) {
        i--;
        if (n & (1 << i)) printf("1");
        else printf("0");
    }
}


uint32_t count(uint32_t x) {
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 1;
}

int main() {
    uint32_t num = 0xff00ff01;
    printBin(num);
    printf("\n");
    printf("%d \n", count(num));
}
