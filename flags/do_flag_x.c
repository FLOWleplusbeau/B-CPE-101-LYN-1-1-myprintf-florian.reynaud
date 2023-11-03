/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** do_flag_x
*/
#include <stdarg.h>
#include "../include/my.h"

static int do_flag_x_left(unsigned long long nb, char *param,
    int *length, int put_length)
{
    int prec = give_precision(param) - put_length;

    if (prec > 0)
        put_length += prec;
    put_prec(length, prec);
    my_putnbr_base(nb, "0123456789abcdef", length);
    fill_flag_nb(param, put_length, length);
}

static int do_flag_x_right(unsigned long long nb, char *param,
    int *length, int put_length)
{
    int prec = give_precision(param) - put_length;

    if (prec > 0)
        put_length += prec;
    fill_flag_nb(param, put_length, length);
    put_prec(length, prec);
    my_putnbr_base(nb, "0123456789abcdef", length);
}

static int do_flag_x_char(va_list list, int *length, char *param)
{
    unsigned int arg = va_arg(list, unsigned int);
    unsigned char nb = (unsigned char)arg;
    int put_length = length_putnbr_base(nb, "0123456789abcdef");

    if (my_char_is_in_str(param, '-')){
        do_flag_x_left(nb, param, length, put_length);
    } else {
        do_flag_x_right(nb, param, length, put_length);
    }
}

static int do_flag_x_short(va_list list, int *length, char *param)
{
    unsigned int arg = va_arg(list, unsigned int);
    unsigned short int nb = (unsigned short int)arg;
    int put_length = length_putnbr_base(nb, "0123456789abcdef");

    if (my_char_is_in_str(param, '-')){
        do_flag_x_left(nb, param, length, put_length);
    } else {
        do_flag_x_right(nb, param, length, put_length);
    }
}

static int do_flag_x_long(va_list list, int *length, char *param)
{
    unsigned long nb = va_arg(list, unsigned long);
    int put_length = length_putnbr_base(nb, "0123456789abcdef");

    if (my_char_is_in_str(param, '-')){
        do_flag_x_left(nb, param, length, put_length);
    } else {
        do_flag_x_right(nb, param, length, put_length);
    }
}

static int do_flag_x_long_long(va_list list, int *length, char *param)
{
    unsigned long long nb = va_arg(list, unsigned long long);
    int put_length = length_putnbr_base(nb, "0123456789abcdef");

    if (my_char_is_in_str(param, '-')){
        do_flag_x_left(nb, param, length, put_length);
    } else {
        do_flag_x_right(nb, param, length, put_length);
    }
}

static int do_flag_x_normal(va_list list, int *length, char *param)
{
    unsigned int nb = va_arg(list, unsigned int);
    int put_length = length_putnbr_base(nb, "0123456789abcdef");

    if (my_char_is_in_str(param, '-')){
        do_flag_x_left(nb, param, length, put_length);
    } else {
        do_flag_x_right(nb, param, length, put_length);
    }
}

int do_flag_x(va_list list, int *length, char *param)
{
    char length_modifier = get_length_modifier(param);

    switch (length_modifier){
        case 'h' + 1:
            return do_flag_x_char(list, length, param);
        case 'h':
            return do_flag_x_short(list, length, param);
        case 'q':
        case 'l' + 1:
            return do_flag_x_long_long(list, length, param);
        case 'l':
            return do_flag_x_long(list, length, param);
        case 0:
            return do_flag_x_normal(list, length, param);
    }
}
