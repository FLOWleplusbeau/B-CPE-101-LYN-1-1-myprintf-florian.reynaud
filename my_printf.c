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

static int do_flag(char *format, int i, va_list list)
{
    typedef int (*func_type)(char *, ...);
    func_type array[256];
    char flag = give_flag(format, i);
    char *param = give_flag_parameters(format, i);

    my_putchar(flag);
    my_putchar('\n');
    my_putstr(param);
    my_putchar('\n');
    free(param);
}

int my_printf(char *format, ...)
{
    va_list list;
    char *args;
    int length = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++){
        if (format[i] == '%'){
            do_flag(format, i, list);
        } 
        else {
            my_putcharl(format[i], &length);
        }
    }
    va_end(list);
    return length;
}
