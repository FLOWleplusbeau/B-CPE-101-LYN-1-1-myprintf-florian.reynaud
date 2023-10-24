/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday11-max.robert
** File description:
** my_put_in_list
*/

#include "mylist.h"
#include "my.h"
#include <stdlib.h>

int my_put_in_list(linked_list_t **list, void *data)
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    element->data = data;
    element->next = *list;
    *list = element;
    return 0;
}
