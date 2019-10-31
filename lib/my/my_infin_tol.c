/*
** EPITECH PROJECT, 2019
** bistro matic
** File description:
** infinstrtol
*/

#include <stdlib.h>
#include <stdio.h>

int my_compute_power_rec(int n, int pow);

void my_putchar(char c);

void my_putstr(char const *str);

int perfect_size(char *str)
{
    int icr = 0;
    while (str[icr] >= '0' && str[icr] <= '9')
        icr += 1;
    return (icr);
}

int    my_delete_spaces(char *str)
{
    int letter = 0;

    while (str[letter] == ' ' && str[letter]) {
        letter += 1;
    }
    if ((str[letter] >= '0' && str[letter] <= '9') && str[letter]) {
        return (letter);
    }
    return (0);
}

char    *my_parser(char *str, int letter, int size, char **endptr)
{
    char *parse;
    parse =  malloc(perfect_size(str));
    char *cpy;

    size += -1;
    while (size >= 0) {
        parse[letter] = str[letter];
        size = size - 1;
        letter = letter + 1;
    }
    *endptr = &str[letter];
    return (parse);
}

char    *my_infin_tol(char *str, char **endptr)
{
    char  *result;
    result = malloc(sizeof(char) * perfect_size(str));
    int size = 0;
    int letter = my_delete_spaces(str);

    if (letter == 0 && str[letter] == '\0') {
        *endptr = &str[letter];
        return (0);
    }
    while ((str[letter] >= '0' && str[letter] <= '9') && str[letter] != '\0') {
        letter = letter + 1;
        size = size + 1;
    }
    letter = letter - size;
    result = my_parser(str, letter, size, endptr);
    return (result);
}