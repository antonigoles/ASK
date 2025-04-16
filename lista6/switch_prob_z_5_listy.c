// stara wersja
long switch_prob(long x, long n) {
    // x - %rdi
    // n - %rsi
    n = n - 60;
    long result; // rax
    switch ((unsigned int)n) {
        case 0:
        case 1:
            // *0x4006f8, *0x400700
            // lea 0x0(,%rdi,8),%rax
            // retq
            return x * 8;
        case 4:
            // 0x4005aa
            // movq %rdi,%rax
            // sarq $0x3,%rax
            // retq
            return x >> 3;
        case 2:
            // *0x400708
            // movq %rdi,%rax
            // shlq $0x4,%rax
            // subq %rdi,%rax
            // movq %rax,%rdi
            result = (x << 4) - x;
            x = result;
        case 5:
            // imulq %rdi,%rdi
            x = x * x;
        case 3:
        default:
            return x + 75;
    }
}
