/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday08-max.robert
** File description:
** my_tablen
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_tablen(char **tab)
{
    int j = 0;

    while (tab[j] != NULL){
        j++;
    }
    return (j);
}
