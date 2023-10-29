/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** give_flag_parameters
*/
#include "include/my.h"
#include <stdlib.h>

static int give_parameters_length(char *format, int i)
{
    int j;
    int length = 0;

    for (j = i + 1; ! is_flag(format, j) || format[j] == '\0'; j++){
        length++;
    }
    return length;
}

char give_flag(char *format, int i)
{
    int j = i + 1;

    while (! is_flag(format, j) || format[j] == '\0'){
        j++;
    }
    return format[j];
}

char *give_flag_parameters(char *format, int i)
{
    char *str;
    int j;
    int length = give_parameters_length(format, i);

    str = malloc(sizeof(char) * (length + 1));
    str[0] = '\0';
    j = i + 1;
    while (is_char_attribut(format, j)){
        my_str_add(str, format[j]);
        j++;
    }
    while (is_precision(format, j)){
        my_str_add(str, format[j]);
        j++;
    }
    while (is_length_modifier(format, j)){
        my_str_add(str, format[j]);
        j++;
    }
    return str;
}
