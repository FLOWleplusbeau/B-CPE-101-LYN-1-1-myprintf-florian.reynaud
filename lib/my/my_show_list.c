/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday11-max.robert
** File description:
** my_show_list
*/

#include "mylist.h"
#include "my.h"
#include <stdlib.h>

void my_show_list(linked_list_t *list)

{
    linked_list_t *tmp;

    tmp = list;
    while (tmp != NULL){
        my_putstr(tmp->data);
        my_putchar('\n');
        tmp = tmp->next;
    }
}
