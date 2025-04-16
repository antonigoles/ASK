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

void slow(uint32_t *x, uint32_t i, uint32_t k) {
    // copy i'th bit to k'th bit in x

    // if i'th bit is on
    if ((*x) & (1 << i)) {
        // fire k'th bit
        *x = (*x) | (1 << k);
    } else {
        // if not, turn off k'th bit
        *x = (*x) & (~(1 << k));
    }
}

void fast(uint32_t *x, uint32_t i, uint32_t k) {
    // lets calculate difference between ith and kth bit
    uint32_t diff = (((*x) >> i) & 1) ^ (((*x) >> k) & 1);
    // apply diff
    *x = (*x) ^ (diff << k);
}

int main() {
    uint32_t num = 0xff00ff00;
    printBin(num);
    printf("\n");
    fast(&num, 8, 2);
    fast(&num, 0, 8);
    printBin(num);
    printf("\n");
}
