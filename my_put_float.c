/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** my_put_float
*/
#include "include/my.h"

void my_put_float(double nb)
{
    int x;
    int nb_int = (int)nb;

    my_put_nbr(nb_int);
    my_putchar('.');
    for (int i = 0; i < 6; i++){
        nb = nb * 10;
        nb_int = (int)nb;
        nb_int = nb_int % 10;
        my_put_nbr(nb_int);
    }
    return;
}

void my_put_float_digits(double nb, int digits)
{
    int x;
    int nb_int = (int)nb;

    my_put_nbr(nb_int);
    if (digits > 0){
        my_putchar('.');
    }
    for (int i = 0; i < digits; i++){
        nb = nb * 10;
        nb_int = (int)nb;
        nb_int = nb_int % 10;
        my_put_nbr(nb_int);
    }
    return;
}
