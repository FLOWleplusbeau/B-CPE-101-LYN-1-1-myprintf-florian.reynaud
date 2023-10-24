/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday03-max.robert
** File description:
** my_isneg
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return 0;
}
