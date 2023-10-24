/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-max.robert
** File description:
** my_strupcase
*/

#include <stdio.h>
#include "my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; i != my_strlen(str) - 1; i++){
        if (str[i] > 96 && str[i] < 123){
            str[i] = str[i] - 32;
        }
    }
    return (str);
}
