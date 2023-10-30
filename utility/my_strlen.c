/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday04-max.robert
** File description:
** my_strlen
*/
#include "../include/my.h"

int my_strlen(char const *str)
{
    int k = 0;

    while (str[k] != '\0'){
        k++;
    }
    return (k);
}
