/*
** EPITECH PROJECT, 2023
** Myprintf
** File description:
** length_put_float
*/

#include <unistd.h>
#include "../include/my.h"

int length_my_put_float(double nb)
{
    int nb_int = (int)nb;
    int length = length_put_nbr(nb_int) + 1;

    for (int i = 0; i < 6; i++){
        nb = nb - nb_int;
        nb = nb * 10;
        nb_int = (int)nb;
        nb_int = nb_int % 10;
        length++;
    }
    return length;
}

int length_my_put_float_digits(double nb, int digits)
{
    int nb_int = (int)nb;
    int length = length_put_nbr(nb_int) + 1;

    for (int i = 0; i < digits; i++){
        nb = nb - nb_int;
        nb = nb * 10;
        nb_int = (int)nb;
        nb_int = nb_int % 10;
        length++;
    }
    return length;
}
