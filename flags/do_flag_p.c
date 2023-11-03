/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** do_flag_p
*/
#include <stdarg.h>
#include "../include/my.h"

static int put_flag_p(void *pointer, char const *base, int *length)
{
    int div = 1;
    unsigned long long res;

    my_putstrl("0x", length);
    my_putnbr_base((unsigned long long)pointer, "0123456789abcdef", length);
}

int do_flag_p(va_list list, int *length, char *param)
{
    void *pointer = va_arg(list, void *);

    put_flag_p(pointer, "0123456789abcdef", length);
}
