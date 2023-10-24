/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-max.robert
** File description:
** my_putnbr_base
*/

#include <unistd.h>
#include "include/my.h"

int my_putnbr_base(unsigned int nbr, char const *base)
{
    int div = 1;
    int res;

    if (nbr < 0){
        my_putchar('-');
        nbr = nbr * - 1;
    }
    while ((nbr / div) >= (my_strlen(base)) - 1){
        div = div *(my_strlen(base));
    }
    for (; div > 0; div = div / (my_strlen(base) - 1)){
        res = (nbr / div) % (my_strlen(base));
        my_putchar(base[res]);
    }
}
