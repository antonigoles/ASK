#include <stdio.h>
#include <stdint.h>

uint32_t zerokthbit(uint32_t n, uint32_t k) {
    return n & (~(1 << k));
}

uint32_t firekthbit(uint32_t n, uint32_t k) {
    return n | (1 << k);
}

uint32_t negatekthbit(uint32_t n, uint32_t k) {
    return n ^ (1 << k);
}

void printBinary(uint32_t n) {
    uint32_t mask = 1 << 31;
    while (mask > 0) {
        if (mask & n) printf("1");
        else printf("0");
        mask >>= 1;
    }
    printf("\n");
}

int main() {
    uint32_t inp = 0b10001000;
    uint32_t res0 = zerokthbit(inp, 3);
    uint32_t res1 = firekthbit(inp, 0);
    uint32_t res2 = negatekthbit(inp, 3);
    uint32_t res3 = negatekthbit(inp, 4);
    printBinary(inp);
    printBinary(res0);
    printBinary(res1);
    printBinary(res2);
    printBinary(res3);
}