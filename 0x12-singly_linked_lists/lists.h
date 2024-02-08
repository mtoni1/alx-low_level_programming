#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>

// Define the list_t struct
typedef struct list_t {
    int n;
    struct list_t *next;
} list_t;

// Function to free a list_t list
void free_list(list_t *head);

// Function to add a new node at the beginning of a list_t list
list_t *add_node(list_t **head, int n);

// Function to add a new node at the end of a list_t list
list_t *add_node_end(list_t **head, int n);

// Function to return the number of elements in a linked list_t list
size_t list_len(const list_t *h);

// Function to print all the elements of a list_t list
size_t print_list(const list_t *h);

// Function to print a single character
int _putchar(char c);

// Function to print You're beat! and yet, you must allow
void print_beat();


#endif // LISTS_H
