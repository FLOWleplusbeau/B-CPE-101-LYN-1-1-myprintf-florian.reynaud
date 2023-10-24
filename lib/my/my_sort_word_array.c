/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday10-max.robert
** File description:
** my_sort_word_array
*/

#include "my.h"
#include <stdio.h>

static void comp(char **tab, int j)
{
    char *temp;

    if (my_strcmp(tab[j], tab[j + 1]) > 0){
        temp = my_strdup(tab[j]);
        tab[j] = my_strdup(tab[j + 1]);
        tab[j + 1] = temp;
    }
}

int my_sort_word_array(char **tab)
{
    for (int i = 0; i < my_tablen(tab); i++){
        for (int j = 0; j < my_tablen(tab) - 1; j++){
            comp(tab, j);
        }
    }
    return 0;
}
