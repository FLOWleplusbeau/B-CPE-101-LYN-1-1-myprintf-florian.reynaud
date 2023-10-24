/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-max.robert
** File description:
** my_strcapitalize
*/

#include <stdio.h>
#include "my.h"

static char if_first(char *str, int i)
{
    if (str[i - 1] < 97 && str[i - 1] > 91){
        str[i] = str[i] - 32;
    }
    if (str[i - 1] < 65 || str[i - 1] > 122){
        str[i] = str[i] - 32;
    }
    return (str[i]);
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; i != my_strlen(str) - 1; i++){
        if (str[i] > 96 && str[i] < 123){
            str[i] = if_first(str, i);
        }
    }
    return (str);
}
