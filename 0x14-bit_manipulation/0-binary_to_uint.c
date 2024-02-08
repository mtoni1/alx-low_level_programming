#include <stdbool.h>
#include "main.h"

/**
 * main - Entry point
 *Function - converts a binary number to an unsigned int
 * Return: Always 0
 */


unsigned int binary_to_uint(const char *b) {
    if (!b) {
        return 0;
    }

    unsigned int result = 0;
    bool is_valid = true;

    while (*b) {
        if (*b != '0' && *b != '1') {
            is_valid = false;
            break;
        }

        result = (result << 1) | (*b == '1');
        b++;
    }

    return is_valid ? result : 0;
}
