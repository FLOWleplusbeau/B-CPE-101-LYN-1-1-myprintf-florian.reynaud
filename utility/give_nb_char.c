/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** give_num_char
*/
#include "../include/my.h"

int give_nb_char(char *param)
{
    int i = 0;
    while (param[i] != '\0' && ! my_char_is_num(param[i]) && param[i] != '.'){
        i++;
    }
    return my_getnbr(param);
}