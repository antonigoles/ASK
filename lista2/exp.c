#include <limits.h>
#include <stdio.h>
#include <stdint.h>

int main() {

    for ( int32_t x = INT_MIN; x<=INT_MAX; x++) {
        for ( int32_t y = INT_MIN; y<=INT_MAX; y++) {
            if (!( x * ~y + (uint32_t)y * (uint32_t)x == -x )) {
                printf("Nie dziala dla %d, %d \n", x, y);
            }
        }
    }
}
