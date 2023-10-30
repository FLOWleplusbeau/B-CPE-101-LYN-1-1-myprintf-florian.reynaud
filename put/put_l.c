/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** put_l
*/
#include <unistd.h>
#include "../include/my.h"

void my_putcharl(char c, int *length)
{
    write(1, &c, 1);
    *length = *length + 1;
}

int my_putstrl(char const *str, int *length)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
        *length = *length + 1;
    }
}

static void print_number(char c)
{
    write(1, &c, 1);
}

int my_put_nbrl(int nb, int *length)
{
    char c = '0';

    if (nb < 0){
        write(1, "-", 1);
        nb = nb * -1;
    }
    while (nb % 10 != 0){
        nb--;
        c++;
    }
    nb /= 10;
    if (nb != 0){
        my_put_nbrl(nb, length);
    }
    *length = *length + 1;
    write(1, &c, 1);
    return (0);
}
