/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** get_length_modifier
*/
#include "../include/my.h"

static char get_length_modifier_step(char *param, int i)
{
    if (is_length_modifier(param, i)){
        switch (param[i + 1]){
            case 'h':
                return ('h' + 1);
            case 'l':
                return ('l' + 1);
            case '\0':
                return param[i];
            default:
                return -1;
        }
    }
}

char get_length_modifier(char *param)
{
    char length_modifier = 0;

    for (int i = 0; param[i] != '\0'; i++){
        length_modifier = get_length_modifier_step(param, i);
        if (length_modifier > 0){
            return length_modifier;
        }
    }
    return length_modifier;
}
