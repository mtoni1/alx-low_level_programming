#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"


/**
* print_list - check the code for Holberton School students.
* @h: name of the list
* Return: the number of nodes.
*/

// Define the list_t struct
typedef struct list_t {
    int n;
    struct list_t *next;
} list_t;

// Function to print all the elements of a list_t list
size_t print_list(const list_t *h) {
    size_t count = 0;
    while (h != NULL) {
        if (count > 0) {
            _putchar(' ');
        }
        if (h->n == INT_MIN) {
            printf("[%d] (nil)", h->n);
        } else {
            printf("[%d]", h->n);
        }
        count++;
        h = h->next;
    }
    _putchar('\n');
    return count;
}

int main() {
    // Create a new list
    list_t *my_list = NULL;

    // Add nodes to the list
    add_node(&my_list, 0);
    add_node(&my_list, 1);
    add_node(&my_list, 2);
    add_node(&my_list, INT_MIN);

    // Print the list
    print_list(my_list);  // Output: [0] [1] [2] [-2147483648] (nil)

    // Free the list
    free_list(my_list);

    // The list has now been freed
    return 0;
}

// Function to add a new node at the beginning of a list_t list
list_t *add_node(list_t **head, int n) {
    // Allocate memory for the new node
    list_t *new_node = (list_t *)malloc(sizeof(list_t));
    if (new_node == NULL) {
        // Allocation failed
        return NULL;
    }

    // Set the n member of the new node to the given value
    new_node->n = n;

    // Set the next pointer of the new node to the current head
    new_node->next = *head;

    // Set the head to the new node
    *head = new_node;

    return new_node;
}

// Function to free a list_t list
void free_list(list_t *head) {
    list_t *current = head;
    while (current != NULL) {
        list_t *next = current->next;
        free(current);
        current = next;
    }
    _putchar('\n');
}
