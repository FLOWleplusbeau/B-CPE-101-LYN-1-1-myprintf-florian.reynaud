/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** flag
*/
#include <stdarg.h>

#ifndef FLAG_H_
    #define FLAG_H_

int do_flag_d(va_list list, int *length, char *param);
int do_flag_i(va_list list, int *length, char *param);
int do_flag_c(va_list list, int *length, char *param);
int do_flag_s(va_list list, int *length, char *param);
int do_flag_x_maj(va_list list, int *length, char *param);
int do_flag_x(va_list list, int *length, char *param);
int do_flag_o(va_list list, int *length, char *param);
int do_flag_u(va_list list, int *length, char *param);
int do_flag_f(va_list list, int *length, char *param);
int do_flag_e(va_list list, int *length, char *param);
int do_flag_e_maj(va_list list, int *length, char *param);
int do_flag_percent(va_list list, int *length, char *param);
int do_flag_p(va_list list, int *length, char *param);
int do_flag_g(va_list list, int *length, char *param);
int do_flag_maj_g(va_list list, int *length, char *param);
int do_flag_n(va_list list, int *length, char *param);

#endif /* !FLAG_H_ */
