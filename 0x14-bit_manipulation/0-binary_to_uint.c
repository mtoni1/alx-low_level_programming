#include "main.h"

/**
 * binary_to_uint - a function that converts a binary number to an unsigned int
 * @b: pointer to a string containing a binary number a string of 0 and 1 chars
 *
 * Return:  the converted number, or 0
 */

unsigned int binary_to_uint(const char *b) {
    if (b == NULL) {
        return 0;
    }

    unsigned int result = 0;
    while (*b != '\0') {
        if (*b != '0' && *b != '1') {
            return 0; // Invalid character in the binary string
        }

        result = (result << 1) | (*b == '1');
        b++;
    }

    return result;
}

#include <stdio.h>

int main() {
    const char *binary = "1011";
    unsigned int result = binary_to_uint(binary);
    _putchar(result);
    return 0;
}
