#include <stdlib.h>
#include <string.h>
/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: double pointer to the address of the list
 * @str: string to store in the new node
 * Return: the address of the new element, or NULL if it failed
 */
typedef struct list_t {
    char *str;
    size_t len;
    struct list_t *next;
} list_t;

list_t *add_node(list_t **head, const char *str) {
    list_t *new;

    new = malloc(sizeof(list_t));
    if (new == NULL) {
        printf("Error: malloc failed\n");
        return NULL;
    }

    new->str = strdup(str);
    if (new->str == NULL) {
        printf("Error: strdup failed\n");
        free(new);
        return NULL;
    }

    new->len = strlen(str);
    new->next = *head;
    *head = new;

    return new;
}
