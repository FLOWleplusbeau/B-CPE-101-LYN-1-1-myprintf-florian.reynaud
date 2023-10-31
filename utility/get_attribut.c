/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** get_attribut
*/
#include "../include/my.h"

char get_attribut(char *param)
{
    if (my_char_is_in_str(param, '+'))
        return '+';
    if (my_char_is_in_str(param, ' '))
        return ' ';
    return 0;
}
