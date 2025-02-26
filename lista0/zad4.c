#include <stdio.h>
#include <stdint.h>


uint32_t x_times_2_to_y(uint32_t x, uint32_t y) {
    return x << y;
}

uint32_t floor_of_x_divided_by_2_to_y(uint32_t x, uint32_t y) {
    return x >> y;
}

uint32_t x_mod_2_to_y(uint32_t x, uint32_t y) {
    return x & ~((~(0b0))<<y);
}

// x / 2^n

uint32_t ceil_of_x_divided_by_2_to_y(uint32_t x, uint32_t y) {
    uint32_t r = x_mod_2_to_y(x, y);
    uint32_t acc = 
        ((r >> 0) & 1) |
        ((r >> 1) & 1) |
        ((r >> 2) & 1) |
        ((r >> 3) & 1) |
        ((r >> 4) & 1) |
        ((r >> 5) & 1) |
        ((r >> 6) & 1) |
        ((r >> 7) & 1) |
        ((r >> 8) & 1) |
        ((r >> 9) & 1) |
        ((r >> 10) & 1) |
        ((r >> 11) & 1) |
        ((r >> 12) & 1) |
        ((r >> 13) & 1) |
        ((r >> 14) & 1) |
        ((r >> 15) & 1) |
        ((r >> 16) & 1) |
        ((r >> 17) & 1) |
        ((r >> 18) & 1) |
        ((r >> 19) & 1) |
        ((r >> 20) & 1) |
        ((r >> 21) & 1) |
        ((r >> 22) & 1) |
        ((r >> 23) & 1) |
        ((r >> 24) & 1) |
        ((r >> 25) & 1) |
        ((r >> 26) & 1) |
        ((r >> 27) & 1) |
        ((r >> 28) & 1) |
        ((r >> 29) & 1) |
        ((r >> 30) & 1) |
        ((r >> 31) & 1);

    return floor_of_x_divided_by_2_to_y(x, y) + acc;
}

int main() {
    // tests
    uint32_t input0 = 16;
    printf("x_times_2_to_y(%d, %d) = %d\n", input0, 2, x_times_2_to_y(input0, 2));
    printf("floor_of_x_divided_by_2_to_y(%d, %d) = %d\n", input0-1, 2, floor_of_x_divided_by_2_to_y(input0-1, 2));
    printf("x_mod_2_to_y(%d, %d) = %d\n", input0+1, 2, x_mod_2_to_y(input0+1, 2));
    printf("ceil_of_x_divided_by_2_to_y(%d, %d) = %d\n", input0+1, 2, ceil_of_x_divided_by_2_to_y(input0+1, 2));
}