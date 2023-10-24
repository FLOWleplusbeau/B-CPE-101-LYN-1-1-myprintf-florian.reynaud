/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-max.robert
** File description:
** my_str_isupper
*/

#include <stdio.h>
#include "my.h"

int my_str_isupper(char const *str)
{
    for (int i = 0; i != my_strlen(str) - 1; i++){
        if (str[i] < 65 || str[i] > 90){
            return (0);
        }
    }
    return (1);
}
