/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** do_flags
*/
#include <stdarg.h>
#include "../include/my.h"

int do_flag_d(va_list list, int *length, char *param)
{
    int nb = va_arg(list, int);
    int put_length = length_put_nbr(nb);

    if (my_char_is_in_str(param, '-')){
        put_operator_printf(nb, param, length, &put_length);
        my_put_nbrl(nb, length);
        fill_flag(param, put_length, length);
    } else {
        put_operator_printf(nb, param, length, &put_length);
        fill_flag(param, put_length, length);
        my_put_nbrl(nb, length);
    }
}

int do_flag_i(va_list list, int *length, char *param)
{
    int nb = va_arg(list, int);
    int put_length = length_put_nbr(nb);

    if (my_char_is_in_str(param, '-')){
        put_operator_printf(nb, param, length, &put_length);
        my_put_nbrl(nb, length);
        fill_flag(param, put_length, length);
    } else {
        put_operator_printf(nb, param, length, &put_length);
        fill_flag(param, put_length, length);
        my_put_nbrl(nb, length);
    }
}

int do_flag_c(va_list list, int *length, char *param)
{
    int c = va_arg(list, int);
    int put_length = length_putchar(c);

    if (my_char_is_in_str(param, '-')){
        my_putcharl(c, length);
        fill_flag(param, put_length, length);
    } else {
        fill_flag(param, put_length, length);
        my_putcharl(c, length);
    }
}

int do_flag_s(va_list list, int *length, char *param)
{
    char *str = va_arg(list, char *);
    int put_length = length_putstr(str);

    if (my_char_is_in_str(param, '-')){
        my_putstrl(str, length);
        fill_flag(param, put_length, length);
    } else {
        fill_flag(param, put_length, length);
        my_putstrl(str, length);
    }
}
