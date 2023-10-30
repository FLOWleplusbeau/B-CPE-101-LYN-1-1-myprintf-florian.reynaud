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

    while (is_char_attribut(param, i)){
        i++;
    }
    return my_getnbr_i(param, i);
}
