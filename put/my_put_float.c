/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** my_put_float
*/

#include "../include/my.h"
#include <stdio.h>

double round_float(double nb, int digits)
{
    double old_nb = nb;
    double nb_add = 10.0;
    int nb_int = (int)nb;

    for (int i = 0; i < digits + 1; i++){
        nb = nb - nb_int;
        nb = nb * 10;
        nb_int = (int)nb;
        nb_int = nb_int % 10;
        nb_add = nb_add / 10;
    }
    if (nb_int >= 5){
        old_nb += nb_add;
    }
    return old_nb;
}

void my_put_float(double nb, int *length)
{
    int nb_int = (int)nb;

    my_put_nbrl(nb_int, length);
    my_putcharl('.', length);
    for (int i = 0; i < 6; i++){
        nb = nb - nb_int;
        nb = nb * 10;
        nb_int = (int)nb;
        nb_int = nb_int % 10;
        my_put_nbrl(nb_int, length);
    }
    return;
}

void my_put_float_digits(double nb, int digits, int *length)
{
    int nb_int = (int)nb;

    my_put_nbrl(nb_int, length);
    if (digits > 0)
        my_putcharl('.', length);
    for (int i = 0; i < digits; i++){
        nb = nb - nb_int;
        nb = nb * 10;
        nb_int = (int)nb;
        nb_int = nb_int % 10;
        my_put_nbrl(nb_int, length);
    }
    return;
}
