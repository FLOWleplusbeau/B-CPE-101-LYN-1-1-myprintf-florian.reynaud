/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-max.robert
** File description:
** my_strlowcase
*/

#include <stdio.h>
#include "my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; i != my_strlen(str) - 1; i++){
        if (str[i] > 64 && str[i] < 91){
            str[i] = str[i] + 32;
        }
    }
    return (str);
}
