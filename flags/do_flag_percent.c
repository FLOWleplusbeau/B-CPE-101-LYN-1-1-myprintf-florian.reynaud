/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** do_flag_percent
*/
#include <stdarg.h>
#include "../include/my.h"

int do_flag_percent(va_list list, int *length, char *param)
{
    my_putcharl('%', length);
}
