/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-max.robert
** File description:
** my_putnbr_base
*/

#include <unistd.h>
#include "../include/my.h"

int my_putnbr_base(unsigned long long nbr, char const *base, int *length)
{
    int base_len = my_strlen(base);
    unsigned long long unit;
    char unit_char;

    if (nbr == 0){
        return (0);
    }
    unit = nbr % base_len;
    unit_char = base[unit];
    my_putnbr_base(nbr / base_len, base, length);
    my_putcharl(unit_char, length);
    return (0);
}
