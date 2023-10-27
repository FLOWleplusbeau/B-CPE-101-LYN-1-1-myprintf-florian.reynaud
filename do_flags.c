/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** do_flags
*/
#include <stdarg.h>
#include "include/my.h"

int do_flag_d(va_list list)
{
    my_put_nbr(va_arg(list, int));
}

int do_flag_i(va_list list)
{
    my_put_nbr(va_arg(list, int));
}

int do_flag_c(va_list list)
{
    my_putchar(va_arg(list, int));
}

int do_flag_s(va_list list)
{
    my_putstr(va_arg(list, char *));
}