/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-max.robert
** File description:
** my_strstr
*/

#include <stdio.h>
#include "my.h"

static int if_str(char *str, char const *to_find, int i)
{
    for (int j = 0; j != my_strlen(to_find) - 1; j++){
        if (str[i + j] != to_find[j]){
            return 0;
        }
    }
    return (1);
}

char *my_strstr(char *str, char const *to_find)
{
    char *res;

    for (int i = 0; i != my_strlen(str) - 1; i++){
        if (if_str(str, to_find, i) == 1){
            res = &str[i];
            return (res);
        }
    }
    return (NULL);
}
