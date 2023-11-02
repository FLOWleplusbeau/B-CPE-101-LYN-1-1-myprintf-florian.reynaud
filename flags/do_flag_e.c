/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** my_put_flagE
*/
#include "../include/my.h"

static void put_flag_e(double nb, char e)
{
    int int_nb = (int)nb;
    int count;

    for (count = 0; nb >= 10; count++){
        nb = nb / 10;
    }
    nb = round_float(nb, 6);
    my_put_float(nb);
    my_putchar(e);
    my_putchar('+');
    if (count < 10)
        my_putchar('0');
    my_put_nbr(count);
    return;
}

static void put_flag_e_digits(double nb, int digits, char e)
{
    int count;

    for (count = 0; nb >= 10; count++){
        nb = nb / 10;
    }
    nb = round_float(nb, digits);
    my_put_float_digits(nb, digits);
    my_putchar(e);
    my_putchar('+');
    if (count < 10)
        my_putchar('0');
    my_put_nbr(count);
    return;
}

static void put_flag_neg_e(double nb, char e)
{
    int int_nb = (int)nb;
    int count;
    int div = 1;

    for (count = 0; nb <= 1; count++){
        nb = nb * 10;
    }
    my_put_float(nb);
    my_putchar(e);
    my_putchar('-');
    if (count < 10)
        my_putchar('0');
    my_put_nbr(count);
    return;
}

static void put_flag_neg_e_digits(double nb, int digits, char e)
{
    int count;

    for (count = 0; nb <= 1; count++){
        nb = nb * 10;
    }
    my_put_float_digits(nb, digits);
    my_putchar(e);
    my_putchar('-');
    if (count < 10)
        my_putchar('0');
    my_put_nbr(count);
    return;
}

static int putl_flag_e(double nb, char e)
{
    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb < 1){
        put_flag_neg_e(nb, e);
    } else {
        put_flag_e(nb, e);
    }
    return 0;
}

int putl_flag_e_digits(double nb, int digits , char e)
{
    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb < 1){
        put_flag_neg_e_digits(nb, digits, e);
    } else {
        put_flag_e_digits(nb, digits, e);
    }
    return 0;
}

static int space_flag_e(va_list list, int *length, char *param, char e)
{
    double nb = va_arg(list, double);
    int put_length = 12;

    if (my_char_is_in_str(param, '-')){
        put_operator_printf(nb, param, length, &put_length);
        putl_flag_e(nb, e);
        fill_flag_nb(param, put_length, length);
    } else {
        put_operator_printf(nb, param, length, &put_length);
        fill_flag_nb(param, put_length, length);
        putl_flag_e(nb, e);
    }
}

static int space_flag_e_digits(va_list list, int *length,
    char *param, int digits)
{
    double nb = va_arg(list, double);
    int put_length = 6 + digits;

    if (my_char_is_in_str(param, '-')){
        put_operator_printf(nb, param, length, &put_length);
        putl_flag_e_digits(nb, digits, 'e');
        fill_flag_nb(param, put_length, length);
    } else {
        put_operator_printf(nb, param, length, &put_length);
        fill_flag_nb(param, put_length, length);
        putl_flag_e_digits(nb, digits, 'e');
    }
}

int do_flag_e(va_list list, int *length, char *param)
{
    int di = give_precision(param);

    if (di == -1){
        space_flag_e(list, length, param, 'e');
    } else {
        space_flag_e_digits(list, length, param, di);
    }
}

int do_flag_e_maj(va_list list, int *length, char *param)
{
    int di = give_precision(param);

    if (di == -1){
        space_flag_e(list, length, param, 'E');
    } else {
        space_flag_maj_e_digits(list, length, param, di);
    }
}
