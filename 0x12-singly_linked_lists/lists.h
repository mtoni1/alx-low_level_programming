#ifndef LIST_H
#define LIST_H

/**
 * @brief Single linked list node
 *
 * @tparam T Type of data stored in the list
 */
typedef struct list_s {
    T data;
    struct list_s *next;
} list_t;

/**
 * @brief Print all the elements of a list
 *
 * @param h Head of the list
 * @return The number of nodes
 */
size_t print_list(const list_t *h);

#endif
