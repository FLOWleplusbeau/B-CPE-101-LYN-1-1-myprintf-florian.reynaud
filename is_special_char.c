/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-florian.reynaud
** File description:
** is_special_char
*/

int is_char_attribut(char *format, int i)
{
    char c = format[i];
    switch (c){
        case '#':
        case '0':
        case '-':
        case '+':
        case ' ':
        case 'I':
            return 1;
        default:
            return 0;
    }
}

int is_length_modifier(char *format, int i)
{
    char c = format[i];
    switch (c){
        case 'h':
        case 'l':
        case 'L':
        case 'q':
        case 'j':
        case 'z':
        case 't':
            return 1;
        default:
            return 0;
    }
}

int is_precision(char *format, int i)
{
    char c = format[i];
    if (c >= '0' && c <= '9'){
        return 1;
    }
    if (c == '.'){
        return 1;
    }
    return 0;
}

static int is_low_flag(char *format, int i)
{
    char c = format[i];
    switch (c){
        case 'd':
        case 'i':
        case 'f':
        case 'e':
        case 'x':
        case 's':
        case 'u':
        case 'p':
        case 'm':
        case 'n':
        case '%':
        case 'g':
        case 'c':
            return 1;
        default:
            return 0;
    }
}

static int is_high_flag(char *format, int i)
{
    char c = format[i];
    switch (c){
        case 'X':
        case 'E':
        case 'F':
        case 'G':
        case 'C':
        case 'S':
            return 1;
        default:
            return 0;
    }
}

int is_flag(char *format, int i)
{
    if (is_high_flag(format, i) || is_low_flag(format, i)){
        return 1;
    }
    return 0;
}