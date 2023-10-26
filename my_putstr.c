/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday04-max.robert
** File description:
** my_putstr
*/

#include "include/my.h"

int my_putstr(char const *str)
{
    char j = *str;
    int k = 0;

    while (j != '\0'){
        j = str[k];
        k = k + 1;
        my_putchar(j);
    }
}
