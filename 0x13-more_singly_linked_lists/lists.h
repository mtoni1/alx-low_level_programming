#ifndef LISTS_H
#define LISTS_H

typedef struct listint_s {
    int value;
    struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);

#endif // LISTS_H
