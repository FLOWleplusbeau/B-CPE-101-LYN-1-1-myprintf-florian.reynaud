/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday05-max.robert
** File description:
** my_find_prime_sup
*/

#include "my.h"

static int check_prime(int nb)
{
    if (nb == 0 || nb == 1){
        return (0);
    }
    for (int i = 2; i <= nb / 2; i = i + 1){
        if (nb % i == 0){
            return (0);
        }
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    if (nb < 0){
        nb = 2;
    }
    while (check_prime(nb) == 0){
        nb = nb + 1;
    }
    return (nb);
}
