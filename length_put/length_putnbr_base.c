/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** length_putnbr_base
*/
#include "../include/my.h"

int length_putnbr_base(unsigned long long nbr, char const *base)
{
    int base_len = my_strlen(base);
    unsigned long long unit;
    char unit_char;
    int put_length = 0;

    if (nbr == 0){
        return (0);
    }
    unit = nbr % base_len;
    unit_char = base[unit];
    put_length += 1;
    put_length += length_putnbr_base(nbr / base_len, base);
    return put_length;
}
