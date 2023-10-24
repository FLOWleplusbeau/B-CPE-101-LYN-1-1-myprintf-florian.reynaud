/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-max.robert
** File description:
** my_strncpy
*/

#include <stdio.h>
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int k = 0;
    char j = src[0];

    if (src[0] == '\0'){
        dest[0] = '\0';
    }
    while (j != '\0' && k != n){
        dest[k] = src[k];
        j = src[k];
        k++;
    }
    if (k > n){
        dest[k] = '\0';
    }
    return (dest);
}
