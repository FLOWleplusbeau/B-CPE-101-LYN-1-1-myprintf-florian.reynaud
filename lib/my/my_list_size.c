/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday11-max.robert
** File description:
** my_list_size
*/

#include "mylist.h"
#include "my.h"
#include <stdlib.h>

int my_list_size(linked_list_t const *begin)
{
    linked_list_t *tmp;
    int count = 0;

    tmp = begin;
    while (tmp != NULL){
        count++;
        tmp = tmp->next;
    }
    return (count);
}
