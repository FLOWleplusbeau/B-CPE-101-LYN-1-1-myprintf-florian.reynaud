/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** my_printf
*/
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

int my_printf(char *format, ...)
{
    va_list list;
    char *args;
    int length = 0;
    int flag_length;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++){
        if (format[i] == '%'){
            flag_length = do_flag(format, i, list, &length);
            i += flag_length;
        } else {
            my_putcharl(format[i], &length);
        }
    }
    my_put_nbr(length);
    va_end(list);
    return length;
}
