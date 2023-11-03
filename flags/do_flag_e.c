/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** my_put_flagE
*/
#include "../include/my.h"

static void put_flag_e(double nb, char e, int *length)
{
    int int_nb = (int)nb;
    int count;

    for (count = 0; nb >= 10; count++){
        nb = nb / 10;
    }
    nb = round_float(nb, 6);
    my_put_float(nb, length);
    my_putcharl(e, length);
    my_putcharl('+', length);
    if (count < 10)
        my_putcharl('0', length);
    my_put_nbrl(count, length);
    return;
}

static void put_flag_e_digits(double nb, int digits, char e, int *length)
{
    int count;

    for (count = 0; nb >= 10; count++){
        nb = nb / 10;
    }
    nb = round_float(nb, digits);
    my_put_float_digits(nb, digits, length);
    my_putcharl(e, length);
    my_putcharl('+', length);
    if (count < 10)
        my_putcharl('0', length);
    my_put_nbrl(count, length);
    return;
}

static void put_flag_neg_e(double nb, char e, int *length)
{
    int int_nb = (int)nb;
    int count;
    int div = 1;

    for (count = 0; nb <= 1; count++){
        nb = nb * 10;
    }
    my_put_float(nb, length);
    my_putcharl(e, length);
    my_putcharl('-', length);
    if (count < 10)
        my_putcharl('0', length);
    my_put_nbrl(count, length);
    return;
}

static void put_flag_neg_e_digits(double nb, int digits, char e, int *length)
{
    int count;

    for (count = 0; nb <= 1; count++){
        nb = nb * 10;
    }
    my_put_float_digits(nb, digits, length);
    my_putcharl(e, length);
    my_putcharl('-', length);
    if (count < 10)
        my_putcharl('0', length);
    my_put_nbrl(count, length);
    return;
}

static int putl_flag_e(double nb, char e, int *length)
{
    if (nb < 0){
        my_putcharl('-', length);
        nb = nb * -1;
    }
    if (nb < 1){
        put_flag_neg_e(nb, e, length);
    } else {
        put_flag_e(nb, e, length);
    }
    return 0;
}

int putl_flag_e_digits(double nb, int digits , char e, int *length)
{
    if (nb < 0){
        my_putcharl('-', length);
        nb = nb * -1;
    }
    if (nb < 1){
        put_flag_neg_e_digits(nb, digits, e, length);
    } else {
        put_flag_e_digits(nb, digits, e, length);
    }
    return 0;
}

int space_flag_e(double nb, int *length, char *param, char e)
{
    int put_length = 12;

    if (my_char_is_in_str(param, '-')){
        put_operator_printf(nb, param, length, &put_length);
        putl_flag_e(nb, e, length);
        fill_flag_nb(param, put_length, length);
    } else {
        put_operator_printf(nb, param, length, &put_length);
        fill_flag_nb(param, put_length, length);
        putl_flag_e(nb, e, length);
    }
}

int space_flag_e_digits(double nb, int *length,
    char *param, int digits)
{
    int put_length = 6 + digits;

    if (my_char_is_in_str(param, '-')){
        put_operator_printf(nb, param, length, &put_length);
        putl_flag_e_digits(nb, digits, 'e', length);
        fill_flag_nb(param, put_length, length);
    } else {
        put_operator_printf(nb, param, length, &put_length);
        fill_flag_nb(param, put_length, length);
        putl_flag_e_digits(nb, digits, 'e', length);
    }
}

int do_flag_e(va_list list, int *length, char *param)
{
    int di = give_precision(param);
    double nb = va_arg(list, double);

    if (di == -1){
        space_flag_e(nb, length, param, 'e');
    } else {
        space_flag_e_digits(nb, length, param, di);
    }
}

int do_flag_e_maj(va_list list, int *length, char *param)
{
    int di = give_precision(param);
    double nb = va_arg(list, double);

    if (di == -1){
        space_flag_e(nb, length, param, 'E');
    } else {
        space_flag_maj_e_digits(nb, length, param, di);
    }
}
