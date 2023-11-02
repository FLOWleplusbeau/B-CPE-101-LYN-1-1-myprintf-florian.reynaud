/*
** EPITECH PROJECT, 2023
** Myprintf
** File description:
** length_flag_e
*/

#include "../include/my.h"

int space_flag_maj_e_digits(va_list list, int *length, char *param, int digits)
{
    double nb = va_arg(list, double);
    int put_length = 6 + digits;

    if (my_char_is_in_str(param, '-')){
        put_operator_printf(nb, param, length, &put_length);
        putl_flag_e_digits(nb, digits, 'E');
        fill_flag_nb(param, put_length, length);
    } else {
        put_operator_printf(nb, param, length, &put_length);
        fill_flag_nb(param, put_length, length);
        putl_flag_e_digits(nb, digits, 'E');
    }
}
