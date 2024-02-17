#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_t {
    int n;
    struct list_t *next;
} list_t;
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
int _strlen(const char *s);
list_t *add_node(list_t **head, const char *str);
unsigned int _strlen(char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
void myStartupFun(void) __attribute__((constructor));
void myStartupFun(void);


#endif
