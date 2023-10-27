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

int do_flag(char *format, int i, va_list list)
{
    typedef int (*func_type)(va_list list);
    func_type array[256];
    int length = 1;
    char flag = give_flag(format, i);
    char *param = give_flag_parameters(format, i);

    array['d'] = do_flag_d;
    array[flag](list);
    length += my_strlen(param);
    free(param);
    return length;
}
