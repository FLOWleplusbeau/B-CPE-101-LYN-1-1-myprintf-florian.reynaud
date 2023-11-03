/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** do_flag_u
*/
#include "../include/my.h"
#include <stdarg.h>

static int do_flag_u_left(unsigned long long nb, char *param,
    int *length, int put_length)
{
    int prec = give_precision(param) - put_length;

    if (prec > 0)
        put_length += prec;
    put_prec(length, prec);
    my_put_unsigned_nbrl(nb, length);
    fill_flag_nb(param, put_length, length);
}

static int do_flag_u_right(unsigned long long nb, char *param,
    int *length, int put_length)
{
    int prec = give_precision(param) - put_length;

    if (prec > 0)
        put_length += prec;
    fill_flag_nb(param, put_length, length);
    put_prec(length, prec);
    my_put_unsigned_nbrl(nb, length);
}

static int do_flag_u_int(va_list list, int *length, char *param)
{
    unsigned int nb = va_arg(list, unsigned int);
    int put_length = length_put_unsigned_nbr(nb);

    if (my_char_is_in_str(param, '-')){
        do_flag_u_left(nb, param, length, put_length);
    } else {
        do_flag_u_right(nb, param, length, put_length);
    }
    return 0;
}

static int do_flag_u_short_int(va_list list, int *length, char *param)
{
    int arg = va_arg(list, int);
    unsigned short int nb = (unsigned short int)arg;
    int put_length = length_put_unsigned_nbr(nb);

    if (my_char_is_in_str(param, '-')){
        do_flag_u_left(nb, param, length, put_length);
    } else {
        do_flag_u_right(nb, param, length, put_length);
    }
    return 0;
}

static int do_flag_u_char(va_list list, int *length, char *param)
{
    int arg = va_arg(list, int);
    unsigned char nb = (unsigned char)arg;
    int put_length = length_put_unsigned_nbr(nb);

    if (my_char_is_in_str(param, '-')){
        do_flag_u_left(nb, param, length, put_length);
    } else {
        do_flag_u_right(nb, param, length, put_length);
    }
    return 0;
}

static int do_flag_u_long(va_list list, int *length, char *param)
{
    unsigned long nb = va_arg(list,unsigned long);
    int put_length = length_put_unsigned_nbr(nb);

    if (my_char_is_in_str(param, '-')){
        do_flag_u_left(nb, param, length, put_length);
    } else {
        do_flag_u_right(nb, param, length, put_length);
    }
    return 0;
}

static int do_flag_u_long_long(va_list list, int *length, char *param)
{
    unsigned long long nb = va_arg(list, unsigned long long);
    int put_length = length_put_unsigned_nbr(nb);

    if (my_char_is_in_str(param, '-')){
        do_flag_u_left(nb, param, length, put_length);
    } else {
        do_flag_u_right(nb, param, length, put_length);
    }
    return 0;
}

int do_flag_u(va_list list, int *length, char *param)
{
    char length_modifier = get_length_modifier(param);

    switch (length_modifier){
        case 'h' + 1:
            return do_flag_u_char(list, length, param);
        case 'h':
            return do_flag_u_short_int(list, length, param);
        case 'l' + 1:
        case 'q':
            return do_flag_u_long_long(list, length, param);
        case 'l':
            return do_flag_u_long(list, length, param);
        case 0:
            return do_flag_u_int(list, length, param);
    }
}