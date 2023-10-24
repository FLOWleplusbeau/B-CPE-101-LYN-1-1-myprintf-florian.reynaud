/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday08-max.robert
** File description:
** my_strdup
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest;

    dest = malloc(sizeof(char) * my_strlen(src));
    my_strcpy(dest, src);
    return (dest);
}
