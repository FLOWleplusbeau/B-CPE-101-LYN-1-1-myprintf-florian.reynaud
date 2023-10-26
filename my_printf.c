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
#include "include/is_special_char.h"
#include "include/my.h"

void my_put_float(double nb);

static void my_putcharl(char c, int *length)
{
    write(1, &c, 1);
    *length = *length + 1;
}

static int my_putstrl(char const *str, int *length)
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

static int my_put_nbrl(int nb, int *length)
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

char *my_str_add(char *dest, char c)
{
    char *temp = dest;
    int len;
    
    len = my_strlen(temp);

    dest[len] = c;
    dest[len + 1] = '\0';
    return dest;
}

char *give_flag_parameters(char *format, int i){
    char *str;
    int length = 1;
    int j;

    for (j = i + 1; ! is_flag(format, j) || format[j] == '\0'; j++){
        length++;
    }
    my_put_nbr(length);
    my_putchar('\n');
    str = malloc(sizeof(char) * (length + 1));
    str[0] = '\0';
    j = i + 1;
    while (is_char_attribut(format, j)){
        my_str_add(str, format[j]);
        j++;
    }
    while (is_precision(format, j)){
        my_str_add(str, format[j]);
        j++;
    }
    while (is_length_modifier(format, j)){
        my_str_add(str, format[j]);
        j++;
    }
    return str;
}

static int do_flag(char *str, int i, va_list list, int *length)
{
    switch (str[i + 1]){
        case 'd':
        case 'i':
            my_put_nbrl(va_arg(list, int), length);
            return 1;
        case 'u':
            my_put_nbrl(va_arg(list, unsigned int), length);
            return 1;
        case 's':
            my_putstrl(va_arg(list, char *), length);
            return 1;
        case 'c':
            my_putcharl(va_arg(list, int), length);
            return 1;
        case '%':
            my_putcharl('%', length);
            return 1;
        case 'o':
            my_putnbr_base(va_arg(list,unsigned int), "01234567");
            return 1;
        case 'x':
            my_putnbr_base(va_arg(list,unsigned int), "0123456789abcdef");
            return 1;
        case 'X':
            my_putnbr_base(va_arg(list,unsigned int), "0123456789ABCDEF");
            return 1;
        case 'f':
            my_put_float(va_arg(list, double));
            return 1;
        case 'p':
            return 1;
        case 'n':
            *va_arg(list, int *) = *length;
            return 1;
        case 'e':
            do_flag_e(va_arg(list, double), 'e');
            return 1;
        case 'E':
            do_flag_e(va_arg(list, double), 'E');
            return 1;
        default:
            my_putcharl('%', length);
            return 0;
    }
}

//return str[i + 1] == '\0';
static int do_error_flag(char *str, int i)
{
    switch (str[i + 1]){
        case '\0':
            return 1;
        default:
            return 0;
    }
}

static int my_printf_error(char *format)
{
    int error = 0;

    for (int i = 0; format[i] != '\0'; i++){
        if (format[i] == '%'){
            error = do_error_flag(format, i);
            i++;
        }
        if (error > 0){
            return 1;
        }
    }
    return 0;
}

int my_printf(char *format, ...)
{
    va_list list;
    char *args;
    int length = 0;

    if (my_printf_error(format) > 0){
        return (-1);
    }
    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++){
        if (format[i] == '%'){
            args = give_flag_parameters(format, i);
            my_putstr(args);
            free(args);
            my_putchar('\n');
            do_flag(format, i, list, &length);
            i++;
        } else {
            my_putcharl(format[i], &length);
        }
    }
    va_end(list);
    return length;
}
