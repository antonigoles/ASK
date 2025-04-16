#include <limits.h>
#include <stdint.h>
#include <stdio.h>


int main() {
    int32_t x = INT_MAX;
    int32_t y = 0;
    int32_t z = 0;

    double dx = (double)x;
    double dy = (double)y;
    double dz = (double)z;
    printf("%d", dx / dx == dz / dz);
}
