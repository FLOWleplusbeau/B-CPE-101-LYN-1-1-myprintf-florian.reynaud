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
    my_put_float(nb);
    my_putchar(e);
    my_putchar('+');
    my_put_nbr(count);
    return ;
}

static void put_flag_e_digits(double nb, int digits, char e)
{
    int count;

    for (count = 0; nb >= 10; count++){
        nb = nb / 10;
    }
    my_put_float_digits(nb, digits);
    my_putchar(e);
    my_putchar('+');
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
    my_put_nbr(count);
    return;
}

static int put_flag_e(double nb, char e)
{
    if (nb < 1){
        put_flag_neg_e(nb, e);
    } else {
        put_flag_e(nb, e);
    }
    return 0;
}

static int put_flag_e_digits(double nb, int digits , char e)
{
    if (nb < 1){
        put_flag_neg_e_digits(nb, digits, e);
    } else {
        put_flag_e_digits(nb, digits, e);
    }
    return 0;
}

int do_flag_e(va_list list, int *length, char *param)
{
    int digits = give_precision(param);

    if (digits == -1){
        put_flag_e(round_float(va_arg(list, double) 6), 'e');
    } else {
        put_flag_e_digits(round_float(va_arg(list, double) digits), digits, 'e');
    }
}

int do_flag_e_maj(va_list list, int *length, char *param)
{
    int digits = give_precision(param);

    if (digits == -1){
        put_flag_e(round_float(va_arg(list, double) 6), 'E');
    } else {
        put_flag_e_digits(round_float(va_arg(list, double) digits), digits, 'E');
    }
}
