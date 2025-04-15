int puzzle(long x, unsigned n) {
    // x- %rdi
    // n - %esi
    if (n == 0) { // testl %esi, %esi
        // .L4
        return n; // move %esi, %eax; ret
    }
    // xorl %edx, %edx - clear %edx
    unsigned index = 0;
    // xorl %eax, %eax - clear %eax
    unsigned turned_on_bit_counter = 0;

    // .L3 block
    do {
        // movl %edi, %ecx; andl $1, %ecx
        // addl %ecx, %eax
        turned_on_bit_counter += x & 1;
        // sarq %rdi
        x >>= 1;
        // incl %edx
        index++;
    } while ( index != n ); // cmpl %edx, $esi; jne .L3

    return turned_on_bit_counter;
}
