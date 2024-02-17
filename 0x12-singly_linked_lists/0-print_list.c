#include "list.h"
#include <stdio.h>

/**
 * print_list - Print all the elements of a list
 * @h: A pointer to the head of the list
 *
 * Return: The number of nodes
 */
size_t print_list(const list_t *h)
{
    size_t count = 0;
    /* Iterate through the list and print each element */
    for (; h != NULL; h = h->next)
    {
        printf("%s\n", h->str); /* Assuming the list contains strings */
        count++;
    }
    return count;
}
