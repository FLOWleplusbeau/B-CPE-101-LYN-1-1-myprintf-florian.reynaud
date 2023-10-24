/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday05-max.robert
** File description:
** my_compute_square_root
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int j = 0;

    while (nb >= 0 ){
        nb = nb - 1 - (2 * j);
        j = j + 1;
        if (nb == 0){
            return (j);
        }
    }
    return (0);
}
