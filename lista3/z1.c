#include <stdint.h>
#include <stdio.h>

// 32 bits for number, 32 for fraction
typedef uint64_t fixed;

void printbin_fixed(uint64_t x, short nl) {
    for (int i = 63; i>=32; i-- ) {
        printf("%lld", (x >> i) & (uint64_t)1);
    }
    printf(".");
    for (int i = 31; i>=0; i-- ) {
        printf("%lld", (x >> i) & (uint64_t)1);
    }
    if (nl) {
        printf("\n");
    }
}

void printbin64(uint64_t x, short nl) {
    for (int i = 63; i>=0; i-- ) {
        printf("%llx", (x >> i) & (uint64_t)1);
    }
    if (nl) {
        printf("\n");
    }
}

void printbin32(uint64_t x, short nl) {
    for (int i = 31; i>=0; i-- ) {
        printf("%llx", (x >> i) & (uint64_t)1);
    }
    if (nl) {
        printf("\n");
    }
}

void print_fixed(fixed num) {
    uint64_t whole = (num & 0xffffffff00000000) >> 32;
    // printbin64(whole, 1);
    uint64_t fracbin = (num & 0xffffffff);
    uint64_t frac = 0;
    for (int i = 0; i<32; i++) {
        frac += (10000000000000 >> (i+1)) * ((fracbin >> (31-i)) & 0b1);
    }
    printf("%llu.", whole);
    char out[14];
    out[13] = '\0';
    for (int i = 0; i<13; i++) {
        out[12-i] = '0' + (frac % 10);
        frac /= 10;
    }
    printf("%s", out);
}

fixed to_fixed(uint32_t n) {
    fixed r = n;
    return r << 32;
}

// frac must be passed as binary
fixed make_fraction(uint32_t whole, uint32_t frac) {
    fixed r = whole;
    return (r << 32) | frac;
}

uint32_t reverse_bin(uint32_t b) {
    uint32_t res = 0;
    for (int i = 0; i<32; i++) {
        res <<= 1;
        res += (b >> i) & 0b1;
    }
    return res;
}

fixed div3(uint32_t n) {
    fixed onethird = make_fraction(0, reverse_bin(0xAAAAAAAA));
    return (n * onethird);
}

int main() {
    // fixed a = to_fixed(25);
    // fixed a = make_fraction(25, 0xf);
    // print_fixed(a);
    // printf("\n");
    // printbin_fixed(a, 1);

    fixed onethird = make_fraction(0, reverse_bin(0xAAAAAAAA));
    printbin_fixed(onethird, 1);
    print_fixed(onethird);
    printf("\n");
    printf("3333333333 / 3 = ");
    print_fixed(div3(3333333333));
    printf("\n");

    printf("\n");
    printf("10000 / 2 = ");
    print_fixed(10000 * make_fraction(0, reverse_bin(0b1111)));
    printf("\n");
}
