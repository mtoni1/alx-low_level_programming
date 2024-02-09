#include"main.h"

/**
 * get_bit - prog returns the value of a bit at a given index.
 * @n: number to check bits in
 * @index: index at which to check bit
 *
 * Return: value of the bit, or -1 if there is an error
 */


int get_bit(unsigned long int n, unsigned int index) {
    if (index > 63) {
        return -1; // Invalid index
    }

    unsigned long int mask = 1 << index;
    return (n & mask) != 0;
}
