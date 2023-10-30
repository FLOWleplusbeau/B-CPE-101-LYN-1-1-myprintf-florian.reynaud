/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** do_flags
*/
#include <stdarg.h>
#include "../include/my.h"

int do_flag_d(va_list list, int *length)
{
    my_put_nbrl(va_arg(list, int), length);
}

int do_flag_i(va_list list, int *length)
{
    my_put_nbrl(va_arg(list, int), length);
}

int do_flag_c(va_list list, int *length)
{
    my_putcharl(va_arg(list, int), length);
}

int do_flag_s(va_list list, int *length)
{
    my_putstrl(va_arg(list, char *), length);
}
