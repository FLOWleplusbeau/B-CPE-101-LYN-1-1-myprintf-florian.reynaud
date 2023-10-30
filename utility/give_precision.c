/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** give_precision
*/

#include "../include/my.h"

int give_precision(char *param)
{
    int i = 0;
    while (param[i] != '.' && param[i] != '\0'){
        i++;
    }
    if (param[i] == '.'){
        i++;
    } else {
        return -1;
    }
    return my_getnbr_i(param,i);
}
