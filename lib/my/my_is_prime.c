/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday05-max.robert
** File description:
**  my_is_prime
*/

#include "my.h"

int my_is_prime(int nb)
{
    if (nb <= 1){
        return (0);
    }
    for (int i = 2; i <= nb / 2; i = i + 1){
        if (nb % i == 0){
            return (0);
        }
    }
    return (1);
}
