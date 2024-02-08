#include <stdbool.h>
#include "lists.h"


/**
* Print list - function that prints all the elements of a listint_t list
*
* Prototype: size_t print_listint(const listint_t *h);
* Return: the number of nodes
*/


size_t print_listint(const listint_t *h) {
    size_t count = 0;

    if (!h) {
        return 0;
    }

    while (h) {
        printf("%d ", h->value);
        h = h->next;
        count++;
    }

    return count;
}
