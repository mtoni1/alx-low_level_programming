#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the list
 * Return: the number of nodes
 */

typedef struct list_t {
    char *str;
    size_t len;
    struct list_t *next;
} list_t;

size_t print_list(const list_t *h) {
    size_t count = 0;

    if (h == NULL) {
        printf("[0] (nil)\n");
        return 0;
    }

    while (h != NULL) {
        printf("[%lu] %s\n", h->len, h->str ? h->str : "[0] (nil)");
        h = h->next;
        count++;
    }

    return count;
}
