/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday03-max.robert
** File description:
** my_swap
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int var = *a;

    *a = *b;
    *b = var;
}
