/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** my_char_is_num
*/

int my_char_is_num(char c)
{
    if (c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}
