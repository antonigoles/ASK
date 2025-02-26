#include <stdio.h>
#include <stdint.h>


uint32_t le_to_be(uint32_t x) {
    return (x << 24) | ((x & 0xff00) << 8) | ((x & 0xff0000) >> 8) | (x >> 24);
}

int main() {
    printf("le_to_be(0x%x) = 0x%x\n", 0x004FEF12, le_to_be(0x004FEF12));
    printf("le_to_be(0x%x) = 0x%x\n", 0xAAAAAAAA, le_to_be(0xAAAAAAAA));
    printf("le_to_be(0x%x) = 0x%x\n", 0x00AAAAAA, le_to_be(0x00AAAAAA));

}
