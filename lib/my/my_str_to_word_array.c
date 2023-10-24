/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday08-max.robert
** File description:
** my_str_to_word_array
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int if_alfnum(char c)
{
    if (!c)
        return 0;
    if ((c < 48 || c > 122) || (c < 97 && c > 90) || (c < 65 && c > 57)){
        return 0;
    }
    return (1);
}

static int nb_word(char const *str)
{
    int count = 0;

    for (int i = 0; i <= my_strlen(str) - 1; i++){
        if (if_alfnum(str[i + 1]) == 0 && if_alfnum(str[i]) == 1){
            count++;
        }
    }
    return (count);
}

static int nb_char_word(char const *str, int w)
{
    int c = 0;
    int count2 = 0;

    for (int i = 0; i <= my_strlen(str) - 1; i++){
        if (if_alfnum(str[i + 1]) == 0 && if_alfnum(str[i]) == 1){
            c++;
        }
        if (if_alfnum(str[i + 1]) == 1 && if_alfnum(str[i]) == 1 && c == w){
            count2++;
        }
    }
    count2++;
    return (count2);
}

static int alloc_str(char const *str, int i, int j, char **tab)
{
    int mem = 0;

    tab[j] = malloc(sizeof(char) * nb_char_word(str, j) + 2);
    for (int k = 0; k < nb_char_word(str, j); k++){
        tab[j][k] = str[i + k];
        mem++;
    }
    tab[j][mem] = '\0';
    return (mem);
}

char **my_str_to_word_array(char const *str)
{
    char **tab;
    int i = 0;
    int j = 0;

    tab = malloc(sizeof(char *) * (nb_word(str) + 1));
    while (i < my_strlen(str)){
        if (if_alfnum(str[i]) == 1){
            i = i + alloc_str(str, i, j, tab) - 1;
            j++;
        }
        i++;
    }
    tab[j] = NULL;
    return (tab);
}
