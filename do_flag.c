/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** do_flag
*/
#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/flag.h"

void make_array(int (**array)())
{
    array['i'] = do_flag_d;
    array['d'] = do_flag_d;
    array['c'] = do_flag_s;
    array['s'] = do_flag_s;
}

int do_flag(char *format, int i, va_list list, int *length)
{
    int (**array)();
    int flag_length = 1;
    char flag = give_flag(format, i);
    char *param = give_flag_parameters(format, i);

    array = malloc(sizeof(int (**)()) * 257);
    make_array(array);
    array[flag](list, length);
    flag_length += my_strlen(param);
    free(param);
    free(array);
    return flag_length;
}
