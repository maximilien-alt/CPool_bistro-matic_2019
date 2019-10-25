/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_bootstrap_2019
** File description:
** eval_expr_bootstrap.c
*/

#include "my.h"

int    eval_expr(char const *str)
{
    char **endptr;
    int number = 0;

    endptr = &str;
    number = my_strtol(endptr[0], endptr);
    return (eval_expr1(endptr, number));
}

int    my_prio_calc1(int number, char **str)
{

    return (number);
}

int    my_prio_calc(int number, char **str)
{
    if (str[0][0] != ')' && str[0][0]) {
        number = number + eval_expr1(str, my_strtol(str[0] + 1, str));
    }
    return (number);
}

int    eval_expr1(char **str, int number)
{
    if (str[0][0] != '\0') {
        if (str[0][0] == '(')
            number = eval_expr1(str, my_prio_calc(number, str));
        if (str[0][0] == '*')
            number = number * eval_expr1(str, my_strtol(str[0] + 1, str));
        if (str[0][0] == '/')
            number = number / eval_expr1(str, my_strtol(str[0] + 1, str));
        if (str[0][0] == '+')
            number = number + eval_expr1(str, my_strtol(str[0] + 1, str));
        if (str[0][0] == '-')
            number = number - eval_expr1(str, my_strtol(str[0] + 1, str));
        if (str[0][0] == '%')
            number = number % eval_expr1(str, my_strtol(str[0] + 1, str));
        if (str[0][0] == ')')
            number = number + eval_expr1(str + 1, my_strtol(str[0] +1, str));
    }
    return (number);
}

int main (int ac , char ** av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
