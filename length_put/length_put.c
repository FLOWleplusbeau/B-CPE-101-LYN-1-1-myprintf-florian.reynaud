/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** put_l
*/
#include <unistd.h>
#include "../include/my.h"

int length_putchar(char c)
{
    return 1;
}

int length_putstr(char const *str)
{
    int length = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        length += 1;
    }
    return length;
}

static int print_number(char c)
{
    return 1;
}

int length_put_nbr(long long nb)
{
    int length = 0;

    if (nb < 0){
        nb = nb * -1;
    }
    while (nb % 10 != 0){
        nb--;
    }
    nb /= 10;
    if (nb != 0){
        length += length_put_nbr(nb);
    }
    length += 1;
    return length;
}

int length_put_unsigned_nbr(unsigned long long nb)
{
    int length = 0;

    if (nb < 0){
        length += 1;
        nb = nb * -1;
    }
    while (nb % 10 != 0){
        nb--;
    }
    nb /= 10;
    if (nb != 0){
        length += length_put_unsigned_nbr(nb);
    }
    length += 1;
    return length;
}
