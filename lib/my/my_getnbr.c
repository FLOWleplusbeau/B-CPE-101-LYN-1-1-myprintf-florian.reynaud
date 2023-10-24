/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday04-max.robert
** File description:
** my_getnbr
*/

#include "my.h"

static int check_op(char a)
{
    if (a == '-' || a == '+'){
        return 1;
    }
    return 0;
}

static int op_changer(int *mem_op, char a)
{
    if (a == '-'){
        *mem_op = *mem_op * (-1);
    }
    return 0;
}

static int check_num(char a)
{
    if (a >= 48 && a <= 57 ){
        return (1);
    }
    return (0);
}

static int check_ov(int mem, int op_mem)
{
    if (mem > 0 && op_mem < 0){
        return (0);
    }
    if (mem < 0 && op_mem > 0){
        return (0);
    }
    return (mem);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int op_mem = 1;
    int mem = 0;

    while (check_op(str[i])){
        op_changer(&op_mem, str[i]);
        i = i + 1;
    }
    while (check_num(str[i])){
        if (check_num(str[i + 1])){
            mem = mem + (str[i] - 48);
            mem = mem * 10;
            i = i + 1;
        } else{
            mem = mem + (str[i] - 48);
            mem = mem * op_mem;
            return (check_ov(mem, op_mem));
        }
    }
}
