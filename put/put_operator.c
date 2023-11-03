/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** put_operator
*/
#include"../include/my.h"

static void choose_op_plus(long long nb, int *length)
{
    if (nb < 0){
        my_putcharl('-', length);
    } else {
        my_putcharl('+', length);
    }
    return;
}

static void choose_op_space(long long nb, int *length)
{
    if (nb < 0){
        my_putcharl('-', length);
    } else {
        my_putcharl(' ', length);
    }
    return;
}

static void choose_op_void(long long nb, int *length, int *put_length)
{
    if (nb < 0){
        my_putcharl('-', length);
        *put_length = *put_length + 1;
    }
    return;
}

void put_operator_printf(long long nb, char *param,
    int *length, int *put_length)
{
    char operator = get_attribut(param);

    if (operator == '+'){
        choose_op_plus(nb, length);
        *put_length = *put_length + 1;
    } else if (operator == ' '){
        choose_op_space(nb, length);
        *put_length = *put_length + 1;
    } else {
        choose_op_void(nb, length, put_length);
    }
    return;
}

static int has_op_is_neg(int nb)
{
    if (nb < 0){
        return 1;
    }
    return 0;
}

int get_has_op(long long nb, char *param, int *length)
{
    char operator = get_attribut(param);

    if (operator == '+'){
        return 1;
    } else if (operator == ' '){
        return 1;
    } else {
        return has_op_is_neg(nb);
    }
    return 0;
}
