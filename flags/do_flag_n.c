/*
** EPITECH PROJECT, 2023
** Myprintf
** File description:
** do_flag_n
*/

#include <stdarg.h>

int do_flag_n(va_list list, int *length, char *param)
{
    *(va_arg(list, int *)) = *length;
}
