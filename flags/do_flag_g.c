/*
** EPITECH PROJECT, 2023
** Myprintf
** File description:
** do_flag_g
*/

#include "../include/my.h"
#include <stdio.h>

static int count_flag_e(double nb)
{
    int count;

    for (count = 0; nb >= 1; count++){
        nb = nb / 10;
    }
    return count;
}

static int do_flag_f_nolist(double nb, int *length, char *param, int digits)
{
    if (digits == -1){
        space_flag_f_digits(nb, length, param, 0);
    } else {
        space_flag_f_digits(nb, length, param, digits);
    }
}

static int do_flag_e_nolist(double nb, int *length, char *param, int di)
{
    if (di == -1){
        space_flag_e_digits(nb, length, param, 0);
    } else {
        space_flag_e_digits(nb, length, param, di);
    }
}

static int do_flag_e_maj_nolist(double nb, int *length, char *param)
{
    int di = give_precision(param);

    if (di == -1){
        space_flag_e(nb, length, param, 'E');
    } else {
        space_flag_maj_e_digits(nb, length, param, di);
    }
}

static int put_flag_g(double nb, int *length, char *param)
{
    int pres;
    int x = count_flag_e(nb);
    int int_nb = (int)nb;

    if (give_precision(param) == -1){
        pres = 6;
    } else {
        pres = give_precision(param);
    }
    if (pres >= x && x >= -4){
        pres = pres - length_put_nbr(int_nb);
        do_flag_f_nolist(nb, length, param, pres);
    } else {
        pres--;
        do_flag_e_nolist(nb, length, param, pres);
    }
}

static int put_flag_maj_g(double nb, int *length, char *param)
{
    int pres;
    int x = count_flag_e(nb);
    int int_nb = (int)nb;

    if (give_precision(param) == -1){
        pres = 6;
    } else {
        pres = give_precision(param);
    }
    if (pres >= x && x >= -4){
        pres = pres - length_put_nbr(int_nb);
        do_flag_f_nolist(nb, length, param, pres);
    } else {
        while (int_nb % 10 == 0)
            int_nb = int_nb / 10;
        pres = pres - length_put_nbr(int_nb) + 1;
        do_flag_e_maj_nolist(nb, length, param);
    }
}

int do_flag_g(va_list list, int *length, char *param)
{
    double nb = va_arg(list, double);
    int int_nb = (int)nb;
    int put_length = length_put_nbr(int_nb);

    if (my_char_is_in_str(param, '-')){
        put_operator_printf(nb, param, length, &put_length);
        put_flag_g(nb, length, param);
        fill_flag_nb(param, put_length, length);
    } else {
        put_operator_printf(nb, param, length, &put_length);
        fill_flag_nb(param, put_length, length);
        put_flag_g(nb, length, param);
    }
}

int do_flag_maj_g(va_list list, int *length, char *param)
{
    double nb = va_arg(list, double);
    int put_length = length_my_put_float(nb);

    if (my_char_is_in_str(param, '-')){
        put_operator_printf(nb, param, length, &put_length);
        put_flag_g(nb, length, param);
        fill_flag_nb(param, put_length, length);
    } else {
        put_operator_printf(nb, param, length, &put_length);
        fill_flag_nb(param, put_length, length);
        put_flag_g(nb, length, param);
    }
}
