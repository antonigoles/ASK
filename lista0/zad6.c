#include <stdio.h>
#include <stdint.h>


void m_swap(uint32_t *a, uint32_t *b) {
    *a = *a ^ *b; // a = a ^ b
    *b = *a ^ *b; // b = (a ^ b) ^ b = a
    *a = *a ^ *b; // a = (a ^ b) ^ a = b 
}

int main() {
    uint32_t a = 184;
    uint32_t b = 75;
    printf("Pre swap = %d, %d\n", a, b);
    m_swap(&a,&b);
    printf("Post swap = %d, %d\n", a, b);
}