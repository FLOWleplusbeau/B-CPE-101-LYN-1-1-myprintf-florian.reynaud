/*
** EPITECH PROJECT, 2023
** Myprintf
** File description:
** do_flag_f
*/

#include "../include/my.h"

int space_flag_f(double nb, int *length, char *param)
{
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

int space_flag_f_digits(double nb, int *length,
    char *param, int digits)
{
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
    double nb = va_arg(list, double);
    int digits = give_precision(param);

    if (digits == -1){
        space_flag_f(nb, length, param);
    } else {
        space_flag_f_digits(nb, length, param, digits);
    }
}
