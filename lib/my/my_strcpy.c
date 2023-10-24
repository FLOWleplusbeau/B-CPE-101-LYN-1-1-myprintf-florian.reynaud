/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-max.robert
** File description:
** my_strcpy
*/

#include <stdio.h>
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int k = 0;
    char j = src[0];

    if (src[0] == '\0'){
        dest[0] = '\0';
    }
    while (j != '\0'){
        dest[k] = src[k];
        j = src[k];
        k++;
    }
    return (dest);
}
