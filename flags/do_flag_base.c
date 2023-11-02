/*
** EPITECH PROJECT, 2023
** Myprintf
** File description:
** do_flag_x
*/
#include <stdio.h>
#include <stdarg.h>
#include "../include/my.h"

int do_flag_x_maj(va_list list, int *length, char *param)
{
    int nb = va_arg(list, int);
    int put_length = length_putnbr_base(nb, "0123456789ABCDEF");
    int prec = give_precision(param) - put_length;

    if (prec > 0)
        put_length += prec;
    if (my_char_is_in_str(param, '-')){
        put_operator_printf(nb, param, length, &put_length);
        put_prec(length, prec);
        my_putnbr_base(nb, "0123456789ABCDEF", length);
        fill_flag_nb(param, put_length, length);
    } else {
        put_operator_printf(nb, param, length, &put_length);
        fill_flag_nb(param, put_length, length);
        put_prec(length, prec);
        my_putnbr_base(nb, "0123456789ABCDEF", length);
    }
}

int do_flag_x(va_list list, int *length, char *param)
{
    int nb = va_arg(list, int);
    int put_length = length_putnbr_base(nb, "0123456789ABCDEF");
    int prec = give_precision(param) - put_length;

    if (prec > 0)
        put_length += prec;
    if (my_char_is_in_str(param, '-')){
        put_operator_printf(nb, param, length, &put_length);
        put_prec(length, prec);
        my_putnbr_base(nb, "0123456789abcdef", length);
        fill_flag_nb(param, put_length, length);
    } else {
        put_operator_printf(nb, param, length, &put_length);
        fill_flag_nb(param, put_length, length);
        put_prec(length, prec);
        my_putnbr_base(nb, "0123456789abcdef", length);
    }
}

int do_flag_o(va_list list, int *length, char *param)
{
    int nb = va_arg(list, int);
    int put_length = length_putnbr_base(nb, "01234567");
    int prec = give_precision(param) - put_length;

    if (prec > 0)
        put_length += prec;
    if (my_char_is_in_str(param, '-')){
        put_operator_printf(nb, param, length, &put_length);
        put_prec(length, prec);
        my_putnbr_base(nb, "01234567", length);
        fill_flag_nb(param, put_length, length);
    } else {
        put_operator_printf(nb, param, length, &put_length);
        fill_flag_nb(param, put_length, length);
        put_prec(length, prec);
        my_putnbr_base(nb, "01234567", length);
    }
}

int do_flag_u(va_list list, int *length, char *param)
{
    int nb = va_arg(list, unsigned int);
    int put_length = length_put_unsigned_nbr(nb);
    int prec = give_precision(param) - put_length;

    if (prec > 0)
        put_length += prec;
    if (my_char_is_in_str(param, '-')){
        put_operator_printf(nb, param, length, &put_length);
        put_prec(length, prec);
        my_put_nbrl(nb, length);
        fill_flag_nb(param, put_length, length);
    } else {
        put_operator_printf(nb, param, length, &put_length);
        fill_flag_nb(param, put_length, length);
        put_prec(length, prec);
        my_put_nbrl(nb, length);
    }
}

static int space_flag_f(va_list list, int *length, char *param)
{
    double nb = va_arg(list, double);
    int put_length = length_my_put_float(nb);

    if (my_char_is_in_str(param, '-')){
        put_operator_printf(nb, param, length, &put_length);
        my_put_float(round_float(nb, 6));
        fill_flag_nb(param, put_length, length);
    } else {
        put_operator_printf(nb, param, length, &put_length);
        fill_flag_nb(param, put_length, length);
        my_put_float(round_float(nb, 6));
    }
}

static int space_flag_f_digits(va_list list, int *length,
    char *param, int digits)
{
    double nb = va_arg(list, double);
    int put_length = length_my_put_float_digits(nb, digits);

    if (my_char_is_in_str(param, '-')){
        put_operator_printf(nb, param, length, &put_length);
        my_put_float_digits(round_float(nb, digits), digits);
        fill_flag_nb(param, put_length, length);
    } else {
        put_operator_printf(nb, param, length, &put_length);
        fill_flag_nb(param, put_length, length);
        my_put_float_digits(round_float(nb, digits), digits);
    }
}

int do_flag_f(va_list list, int *length, char *param)
{
    int digits = give_precision(param);

    if (digits == -1){
        space_flag_f(list, length, param);
    } else {
        space_flag_f_digits(list, length, param, digits);
    }
}
