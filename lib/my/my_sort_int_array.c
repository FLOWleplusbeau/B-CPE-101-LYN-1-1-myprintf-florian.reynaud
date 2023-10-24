/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday04-max.robert
** File description:
** my_sort_int_array
*/

#include <stdio.h>
#include "my.h"

static void my_swap2(int *a, int *b)
{
    int var = *a;

    *a = *b;
    *b = var;
}

static int sort(int *array, int size, int i)
{
    if (array[i] > array[i + 1]){
            my_swap2(&array[i], &array[i + 1]);
        }
    return 0;
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i != size; i++){
        for (int j = 0; j != size - 1; j++){
            sort(array, size, j);
        }
    }
    return;
}
