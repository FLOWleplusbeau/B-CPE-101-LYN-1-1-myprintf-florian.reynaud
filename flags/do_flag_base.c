/*
** EPITECH PROJECT, 2023
** Myprintf
** File description:
** do_flag_x
*/
#include <stdarg.h>
#include "../include/my.h"

int do_flag_X(va_list list, int *length)
{
    my_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF");
}

int do_flag_x(va_list list, int *length)
{
    my_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef");
}

int do_flag_o(va_list list, int *length)
{
    my_putnbr_base(va_arg(list, unsigned int), "01234567");
}

int do_flag_u(va_list list, int *length)
{
    my_put_nbrl(va_arg(list, unsigned int), length);
}
