/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-max.robert
** File description:
** my_strncmp
*/

#include <stdio.h>
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int var_s1 = 0;
    int var_s2 = 0;

    for (int i = 0 ; i != n; i++){
        var_s1 = var_s1 + s1[i];
        var_s2 = var_s2 + s2[i];
    }
    if (var_s1 < var_s2){
        return (-1);
    }
    if (var_s1 == var_s2){
        return (0);
    }
    if (var_s1 > var_s2){
        return (1);
    }
}
