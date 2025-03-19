#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lib.h"

linked_list_t *new_list(char **av)
{
    linked_list_t *list;

    while (*av) {
        linked_list_t *new = malloc(sizeof(linked_list_t));
        new->data = *av;
        new->next = list;
        list = new;
        av++;
    }
    linked_list_t *last_elem = malloc(sizeof(linked_list_t));
    last_elem->data = *av;
    last_elem->next = list;
    list = last_elem;
    return list;
}

linked_list_t *new_node(linked_list_t *list, void *data)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));
    
    new->data = data;
    new->next = list;
    return new;
}

void destroy_list(linked_list_t *list)
{
    linked_list_t *temp;
    while (list) {
        my_put_str(list->data);
        write(1, "\n", 1);
        temp = list;
        list = list->next;
        free(temp);
    }
}

linked_list_t *get_last(linked_list_t *list)
{
    while (list && list->next)
        list = list->next;
    return list;
}


void my_sort_list(linked_list_t **begin, int(*cmp)())
{
    linked_list_t *start = begin;
    int is_sorted = 1;
    void *temp;

    while (is_sorted) {
        is_sorted = 0;
        while (start) {
            if ((cmp)(start->data, start->next->data) > 0) {
                temp = start->next->data;
                start->next->data = start->data;
                start->data = temp;
                ++is_sorted;
            }
            start = start->next;
        }
        start = *begin;
    }
}

char **sort_array(char **array)
{
    char *ptr = array;
    char sorted = 1;
    char *temp;

    while (sorted) {
        sorted = 0;
        while (*(ptr + 1)) {
            if (my_strcmp(*ptr, *(ptr + 1)) > 0) {
                temp = *ptr;
                *ptr = *(ptr + 1);
                *(ptr + 1) = temp;
                ++sorted;
            }
            ++ptr;
        }
        ptr = array;
    }
    return array;
}