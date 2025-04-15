#include <stdio.h>


// This function calculates k, where k is the maximum index
// such that for all i<=k, s[i] appears in d at least once
long puzzle2(char *s, char *d) {
    char *current_s_position = s;

    while (1) {
        // let's take the next character from s starting from the first
        char current_s_char = *(current_s_position);
        char *next_s_position = current_s_position + 1;
        char *current_d_position = d;

        char current_d_char;
        do {
            // now starting from the first character in d
            current_d_char = *current_d_position;
            current_d_position++;

            // if we reached the end of d then we should return difference between
            // reached position of s and the starting position of s
            if (current_d_char == '\0') {
                current_s_position = current_s_position - (long)s;
                return (long)current_s_position;
            }

            // go over next chars from s until the targeted char is different
        } while (current_d_char != current_s_char);

        // move to the next char from s
        current_s_position = next_s_position;
    }
}

int main() {
    printf("%ld\n", puzzle2("aaaabcdxeffff", "aabcddddefasdasdassa"));
}
