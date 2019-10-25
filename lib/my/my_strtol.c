/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_bootstrap_2019
** File description:
** evalexpr_bootstrap.c
*/

#include <stdlib.h>

int my_compute_power_rec(int n, int pow);

void my_putchar(char c);

void my_putstr(char const *str);

int    my_str_tol_error(char const *str)
{
    int letter = 0;

    if (str[letter] == '+') {
        my_putstr("Numerical result out of range");
        my_putchar('\n');
        return (0);
    }
    if (str[letter] == '\0') {
        return (0);
    }
    return (0);
}

int    my_delete_non_null(char const *str)
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

int    my_int_nbr(char const *str, int letter, int size, char **endptr)
{
    int number = 0;
    char *cpy;

    size += -1;
    while (size >= 0) {
        number = number + ((str[letter] - 48) * my_compute_power_rec(10, size));
        if (number < 0) {
            cpy = malloc(sizeof(char) * 2);
            cpy[0] = '+';
            cpy[1] = '\0';
            return (my_str_tol_error(cpy));
            free(cpy);
        }
        size = size - 1;
        letter = letter + 1;
    }
    *endptr = &str[letter];
    return (number);
}

int    my_strtol(char const *str, char **endptr)
{
    int number = 0;
    int size = 0;
    int letter = my_delete_non_null(str);

    if (letter == 0 && str[letter] == '\0') {
        *endptr = &str[letter];
        return (my_str_tol_error(str));
    }
    while ((str[letter] >= 48 && str[letter] <= 57) && str[letter] != '\0') {
        letter = letter + 1;
        size = size + 1;
    }
    letter = letter - size;
    number = my_int_nbr(str, letter, size, endptr);
    return (number);
}
