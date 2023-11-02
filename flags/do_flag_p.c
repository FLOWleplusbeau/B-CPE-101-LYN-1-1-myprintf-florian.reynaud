/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** do_flag_p
*/
#include <stdarg.h>
#include "../include/my.h"

static int put_flag_p(unsigned long nbr, char const *base, int *length)
{
    int div = 1;
    int res;

    if (nbr < 0){
        my_putcharl('-', length);
        nbr = nbr * - 1;
    }
    while ((nbr / div) >= (my_strlen(base)) - 1){
        div = div *(my_strlen(base));
    }
    for (; div > 0; div = div / (my_strlen(base) - 1)){
        res = (nbr / div) % (my_strlen(base));
        my_putcharl(base[res], length);
    }
}

int do_flag_p(va_list list, int *length, char *param)
{
    void *pointer = va_arg(list, void *);
    unsigned long int_pointer = (unsigned long)pointer;

    put_flag_p(int_pointer, "0123456789abcdef", length);
}
