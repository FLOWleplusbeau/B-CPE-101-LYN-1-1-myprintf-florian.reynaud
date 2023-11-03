/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday07-max.robert
** File description:
** header
*/

#include <stdarg.h>

#ifndef HEADER_H_
    #define HEADER_H_

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);

//paenlevè
int my_printf(char *format, ...);
char *my_str_add(char *dest, char c);
void my_put_float(double nb);
int my_putnbr_base(unsigned long long nbr, char const *base, int *length);
char *give_flag_parameters(char *format, int i);
int is_char_attribut(char *format, int i);
int is_length_modifier(char *format, int i);
int is_precision(char *format, int i);
int is_flag(char *format, int i);
void my_put_float_digits(double nb, int digits);
void my_put_float(double nb);
void my_putcharl(char c, int *length);
int my_putstrl(char const *str, int *length);
int my_put_nbrl(long long nb, int *length);
char give_flag(char *format, int i);
int do_flag(char *format, int i, va_list list, int *length);
int my_char_is_in_str(char *str, char c);
int my_char_is_num(char c);
int my_put_unsigned_nbrl(unsigned int nb, int *length);
int give_nb_char(char *param);
int my_getnbr(char const *str);
int my_getnbr_i(char const *str, int i);
int give_precision(char *param);
double round_float(double nb, int digits);
int length_putchar(char c);
int length_putstr(char const *str);
int length_put_nbr(long long nb);
int length_put_unsigned_nbr(unsigned int nb);
int length_putnbr_base(unsigned long long nbr, char const *base);
void fill_flag(char *param, int put_length, int *length);
char get_attribut(char *param);
void put_operator_printf(long long nb, char *param,
    int *length, int *put_length);
void fill_flag_nb(char *param, int put_length, int *length);
void fill_flag_0(char *param, int put_length, int *length);
int put_prec(int *length, int prec);
int length_my_put_float(double nb);
int length_my_put_float_digits(double nb, int digits);
int space_flag_maj_e_digits(double nb, int *length, char *param, int digit);
int putl_flag_e_digits(double nb, int digits , char e);
int space_flag_e_digits(double nb, int *length,
    char *param, int digits);
int space_flag_e(double nb, int *length, char *param, char e);
int space_flag_f_digits(double nb, int *length,
    char *param, int digits);
int space_flag_f(double nb, int *length, char *param);
=======
int get_has_op(long long nb, char *param, int *length);
char get_length_modifier(char *param);


#endif /* !HEADER_H_ */
