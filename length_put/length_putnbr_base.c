/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** length_putnbr_base
*/
#include "../include/my.h"

int length_putnbr_base(unsigned int nbr, char const *base)
{
    int div = 1;
    int res;
    int length = 0;

    if (nbr < 0){
        length += length_putchar('-');
        nbr = nbr * - 1;
    }
    while ((nbr / div) >= (my_strlen(base)) - 1){
        div = div *(my_strlen(base));
    }
    for (; div > 0; div = div / (my_strlen(base) - 1)){
        res = (nbr / div) % (my_strlen(base));
        length += length_putchar(base[res]);
    }
    return length;
}
