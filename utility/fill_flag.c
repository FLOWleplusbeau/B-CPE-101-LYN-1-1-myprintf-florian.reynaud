/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** fill_flag
*/
#include "../include/my.h"

static char get_filler(char *param)
{
    int i = 0;

    if (my_char_is_in_str(param, '-')){
        return ' ';
    }
    while (is_char_attribut(param, i) && param[i] != '\0'){
        if (param[i] == '0'){
            return '0';
        }
        i++;
    }
    return ' ';
}

void fill_flag(char *param, int put_length, int *length)
{
    int min_length = give_nb_char(param);
    char filler = ' ';

    while (min_length - put_length > 0){
        my_putcharl(filler, length);
        min_length -= 1;
    }
    return;
}

void fill_flag_0(char *param, int put_length, int *length)
{
    int min_length = give_nb_char(param);
    char filler = '0';

    while (min_length - put_length > 0){
        my_putcharl(filler, length);
        min_length -= 1;
    }
    return;
}

void fill_flag_nb(char *param, int put_length, int *length)
{
    int min_length = give_nb_char(param);
    char filler = get_filler(param);

    while (min_length - put_length > 0){
        my_putcharl(filler, length);
        min_length -= 1;
    }
    return;
}
