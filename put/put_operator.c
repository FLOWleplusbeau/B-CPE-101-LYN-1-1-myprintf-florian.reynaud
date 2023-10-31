/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** put_operator
*/
#include"../include/my.h"

void put_operator_printf(int nb, char *param, int *length, int *put_length)
{
    char operator = get_attribut(param);

    if (operator == '+'){
        if (nb < 0){
            my_putcharl('-', length);
        } else {
            my_putcharl('+', length);
        }
        *put_length = *put_length + 1;
    } else if (operator == ' '){
        if (nb < 0){
            my_putcharl('-', length);
        } else {
            my_putcharl(' ', length);
        }
        *put_length = *put_length + 1;
    }
    return;
}
