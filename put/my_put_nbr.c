/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday03-max.robert
** File description:
** my_put_nbr
*/

#include "../include/my.h"

int my_put_nbr(int nb)
{
    char n = '0';

    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
    }
    while (nb % 10 != 0){
        nb--;
        n++;
    }
    nb = nb / 10;
    if (nb != 0){
        my_put_nbr(nb);
    }
    my_putchar(n);
}
