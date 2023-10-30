/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** my_char_is_in_str
*/

int my_char_is_in_str(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == c){
            return 1;
        }
    }
    return 0;
}
