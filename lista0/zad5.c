#include <stdio.h>
#include <stdint.h>


uint32_t comp(uint32_t x) {
    return x ^ 0b11111111111111111111111111111111;
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
    printf("comp(01010111) = ");
    printBinary(comp(0b01010111));
}