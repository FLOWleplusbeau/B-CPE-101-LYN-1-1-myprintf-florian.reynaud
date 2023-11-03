/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** do_flag_d
*/
#include "../include/my.h"

static int do_flag_d_left(long long nb, char *param,
    int *length, int put_length)
{
    int prec = give_precision(param) - put_length;
    int has_op = get_has_op(nb, param, length);

    if (! my_char_is_in_str(param, '-'))
        put_length += has_op;
    if (put_length > 0 && ! my_char_is_in_str(param, '.'))
        prec = give_nb_char(param) - put_length;
    if (prec > 0)
        put_length += prec;
    put_operator_printf(nb, param, length, &put_length);
    put_prec(length, prec);
    my_put_nbrl(nb, length);
    fill_flag_nb(param, put_length, length);
}

static int do_flag_d_right(long long nb, char *param,
    int *length, int put_length)
{
    int prec = give_precision(param) - put_length;
    int has_op = get_has_op(nb, param, length);

    if (! my_char_is_in_str(param, '-'))
        put_length += has_op;
    if (put_length > 0 && ! my_char_is_in_str(param, '.'))
        prec = give_nb_char(param) - put_length;
    if (prec > 0)
        put_length += prec;
    fill_flag_nb(param, put_length, length);
    put_operator_printf(nb, param, length, &put_length);
    put_prec(length, prec);
    my_put_nbrl(nb, length);
}

static int do_flag_d_int(va_list list, int *length, char *param)
{
    int nb = va_arg(list, int);
    int put_length = length_put_nbr(nb);

    if (my_char_is_in_str(param, '-')){
        do_flag_d_left(nb, param, length, put_length);
    } else {
        do_flag_d_right(nb, param, length, put_length);
    }
    return 0;
}

static int do_flag_d_short_int(va_list list, int *length, char *param)
{
    int arg = va_arg(list, int);
    short int nb = (short int)arg;
    int put_length = length_put_nbr(nb);

    if (my_char_is_in_str(param, '-')){
        do_flag_d_left(nb, param, length, put_length);
    } else {
        do_flag_d_right(nb, param, length, put_length);
    }
    return 0;
}

static int do_flag_d_char(va_list list, int *length, char *param)
{
    int arg = va_arg(list, int);
    char nb = (char)arg;
    int put_length = length_put_nbr(nb);

    if (my_char_is_in_str(param, '-')){
        do_flag_d_left(nb, param, length, put_length);
    } else {
        do_flag_d_right(nb, param, length, put_length);
    }
    return 0;
}

static int do_flag_d_long(va_list list, int *length, char *param)
{
    long nb = va_arg(list, long);
    int put_length = length_put_nbr(nb);

    if (my_char_is_in_str(param, '-')){
        do_flag_d_left(nb, param, length, put_length);
    } else {
        do_flag_d_right(nb, param, length, put_length);
    }
    return 0;
}

static int do_flag_d_long_long(va_list list, int *length, char *param)
{
    long long nb = va_arg(list, long long);
    int put_length = length_put_nbr(nb);

    if (my_char_is_in_str(param, '-')){
        do_flag_d_left(nb, param, length, put_length);
    } else {
        do_flag_d_right(nb, param, length, put_length);
    }
    return 0;
}

int do_flag_d(va_list list, int *length, char *param)
{
    char length_modifier = get_length_modifier(param);

    switch (length_modifier){
        case 'h' + 1:
            return do_flag_d_char(list, length, param);
        case 'h':
            return do_flag_d_short_int(list, length, param);
        case 'l' + 1:
        case 'q':
            return do_flag_d_long_long(list, length, param);
        case 'l':
            return do_flag_d_long(list, length, param);
        case 0:
            return do_flag_d_int(list, length, param);
    }
}
