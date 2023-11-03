/*
** EPITECH PROJECT, 2023
** Myprintf
** File description:
** do_flag_n
*/
#include "../include/my.h"
#include <stdarg.h>

static int do_flag_n_char(va_list list, int *length, char *param)
{
    *(va_arg(list, char *)) = *length;
}

static int do_flag_n_short(va_list list, int *length, char *param)
{
    *(va_arg(list, short int *)) = *length;
}

static int do_flag_n_int(va_list list, int *length, char *param)
{
    *(va_arg(list, int *)) = *length;
}

static int do_flag_n_long(va_list list, int *length, char *param)
{
    *(va_arg(list, long *)) = *length;
}

static int do_flag_n_long_long(va_list list, int *length, char *param)
{
    *(va_arg(list, long long *)) = *length;
}

int do_flag_n(va_list list, int *length, char *param)
{
    char length_modifier = get_length_modifier(param);

    switch (length_modifier){
        case 'h' + 1:
            return do_flag_n_char(list, length, param);
        case 'h':
            return do_flag_n_short(list, length, param);
        case 'q':
        case 'l' + 1:
            return do_flag_n_long_long(list, length, param);
        case 'l':
            return do_flag_n_long(list, length, param);
        case 0:
            return do_flag_n_int(list, length, param);
    }
}
