/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-mywprintf-florian.reynaud
** File description:
** my_printf
*/
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

static void my_putchar(char c, int *length)
{
    write(1, &c, 1);
    *length = *length + 1;
}

static int my_putstr(char const *str, int *length)
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

static int my_put_nbr(int nb, int *length)
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
        my_put_nbr(nb, length);
    }
    *length = *length + 1;
    write(1, &c, 1);
    return (0);
}

static int flag_n(int nb, int *c)
{
    int *d = &c;

    &d = nb;
    return 0;
}

static int do_flag(char *str, int i, va_list list, int *length)
{
    switch (str[i + 1]){
        case 'd':
        case 'i':
            my_put_nbr(va_arg(list, int), length);
            return 1;
        case 'u':
            my_put_nbr(va_arg(list, unsigned int), length);
            return 1;
        case 's':
            my_putstr(va_arg(list, char *), length);
            return 1;
        case 'c':
            my_putchar(va_arg(list, int), length);
            return 1;
        case '%':
            my_putchar('%', length);
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
        case 'n':
            *(va_arg(list, int *)) = length;
            return 1;
        default:
            my_putchar('%', length);
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

static int printf_error(char *format)
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

int printf(char *format, ...)
{
    va_list list;
    int length = 0;

    if (printf_error(format) > 0){
        return (-1);
    }
    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++){
        if (format[i] == '%'){
            do_flag(format, i, list, &length);
            i++;
        } else {
            my_putchar(format[i], &length);
        }
    }
    va_end(list);
    return length;
}
