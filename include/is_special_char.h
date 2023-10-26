/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** is_special_char
*/

#ifndef IS_SPECIAL_CHAR_H_
    #define IS_SPECIAL_CHAR_H_

int is_char_attribut(char *format, int i);
int is_length_modifier(char *format, int i);
int is_precision(char *format, int i);
int is_flag(char *format, int i);
void my_put_float_digits(double nb, int digits);
void my_put_float(double nb);
void do_flag_e(double nb, char e);
void do_flag_e_digits(double nb,int digits , char e);

#endif /* !IS_SPECIAL_CHAR_H_ */
