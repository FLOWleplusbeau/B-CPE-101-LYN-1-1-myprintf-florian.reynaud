/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday07-max.robert
** File description:
** my_strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int k = my_strlen(dest);

    for (int i = 0; i != nb; i++){
        dest[k + i] = src[i];
    }
    dest[k + my_strlen(src)] = '\0';
}
