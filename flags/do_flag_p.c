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
    my_putstrl("0x", length);
    my_putnbr_base((unsigned long long)pointer, base, length);
}

static int length_put_flag_p(void *pointer, char const *base)
{
    int length = 2;

    length += length_putnbr_base((unsigned long long)pointer, base);
    return length;
}

int do_flag_p(va_list list, int *length, char *param)
{
    void *pointer = va_arg(list, void *);

    put_flag_p(pointer, "0123456789abcdef", length);
}
