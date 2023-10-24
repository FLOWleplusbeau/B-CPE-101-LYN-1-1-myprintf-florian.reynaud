/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-max.robert
** File description:
** my_revstr
*/

#include <stdio.h>
#include "my.h"

char *my_revstr(char *str)
{
    int nb = my_strlen(str) - 2;
    char var;

    for (int i = 0; i < nb; i++){
        var = str[nb];
        str[nb] = str[i];
        str[i] = var;
        nb--;
    }
    return (str);
}
