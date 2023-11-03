/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** do_flag
*/
#include <stdarg.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/flag.h"

void make_array(int (**array)())
{
    for (int i = 0; i < 257; i++){
        array[i] = do_flag_d;
    }
    array['i'] = do_flag_d;
    array['d'] = do_flag_d;
    array['c'] = do_flag_c;
    array['s'] = do_flag_s;
    array['x'] = do_flag_x;
    array['X'] = do_flag_x_maj;
    array['o'] = do_flag_o;
    array['u'] = do_flag_u;
    array['f'] = do_flag_f;
    array['e'] = do_flag_e;
    array['E'] = do_flag_e_maj;
    array['F'] = do_flag_f;
    array['%'] = do_flag_percent;
    array['p'] = do_flag_p;
    array['g'] = do_flag_g;
    array['G'] = do_flag_maj_g;
    array['n'] = do_flag_n;
}

int do_flag(char *format, int i, va_list list, int *length)
{
    int (**array)();
    int flag_length = 1;
    char flag = give_flag(format, i);
    char *param = give_flag_parameters(format, i);

    array = malloc(sizeof(int (**)()) * 257);
    make_array(array);
    array[flag](list, length, param);
    flag_length += my_strlen(param);
    free(param);
    free(array);
    return flag_length;
}
