#include <stddef.h>
#include <stdio.h>

/**
* print_list - prints all the elements of a list_t list
* @h: pointer to the list
* Return: the number of nodes
*/
struct list_t {
const char* str;
unsigned int len;
struct list_t* next;
};

size_t print_list(const list_t* h) {
size_t count = 0;

while (h != NULL) {
if (h->str == NULL) {
printf("[0] ");
} else {
printf("%s ", h->str);
}

++count;
h = h->next;
}

putchar('\n');
return count;
}
