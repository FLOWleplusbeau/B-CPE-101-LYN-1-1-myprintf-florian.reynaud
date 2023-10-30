/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** flag
*/
#include <stdarg.h>

#ifndef FLAG_H_
    #define FLAG_H_

int do_flag_d(va_list list, int *length);
int do_flag_i(va_list list, int *length);
int do_flag_c(va_list list, int *length);
int do_flag_s(va_list list, int *length);
int do_flag_X(va_list list, int *length);
int do_flag_x(va_list list, int *length);
int do_flag_o(va_list list, int *length);
int do_flag_u(va_list list, int *length);

#endif /* !FLAG_H_ */
