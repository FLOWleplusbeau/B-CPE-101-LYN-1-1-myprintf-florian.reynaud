/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday07-max.robert
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int k = my_strlen(dest);

    for (int i = 0; i != my_strlen(src); i++){
        dest[k + i] = src[i];
    }
    dest[k + my_strlen(src)] = '\0';
}
