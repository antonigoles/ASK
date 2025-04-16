#include <stdio.h>

// x - %rdi , y - %rsi
// return - %rax
long long_decode(long x, long y) {
    // leaq (%rdi,%rsi), %rax
    long result = x + y;

    // 2 xorq %rax, %rdi
    result ^= x;

    // 3 xorq %rax, %rsi
    result ^= y;

    // 4 movq %rdi, %rax
    x = result;

    // 5 andq %rsi, %rax
    result &= y;

    // 6 shrq $63, %rax
    result = result >> 63;

    // 7 ret
    return result;
}

long fast_decode(long x, long y) {
    return ((((x + y) ^ x) ^ y) & y) >> 63;
}

int main() {

}
