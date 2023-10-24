/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-max.robert
** File description:
** my_getnbr_base
*/

#include <stdio.h>

int my_compute_power_rec02(int nb, int p)
{
    if (p == 0){
        return (1);
    }
    if (p < 0){
        return (0);
    }
    if (p != 1){
        nb = nb * my_compute_power_rec02(nb, p - 1);
    }
    return (nb);
}

int my_getnbr_base(char const *str, char const *base)
{
    int res = 0;
    int neg = 1;
    int j = 0;
    int k = (my_strlen(str) - 1);
    int mem = 0;

    if (str[j] == '-'){
        neg = neg * - 1;
        j++;
    }
    for (; j < my_strlen(str) - 1; j++){
        for (int l = 0; str[j] != base[l]; l++){
            mem = l;
        }
        mem++;
        res = res + (mem* my_compute_power_rec02(my_strlen(base) - 1, k));
        k--;
    }
    res = res * neg;
    return (res);
}
