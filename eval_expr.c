/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_bootstrap_2019
** File description:
** eval_expr_bootstrap.c
*/

#include "include/my.h"

char *my_infin_mult(char *str, char *mult);

char *my_infin_div(char *str, char *div);

char *my_infin_mod(char *str, char *div);

char *eval_expr1(char **str, char *number);

char    *eval_expr(char *str)
{
    char **endptr;
    char *number;

    endptr = &str;
    number = my_infin_tol(endptr[0], endptr);
    return (eval_expr1(endptr, number));
}

char    *my_prio_calc(char *number,  char **str)
{
    if (str[0][0] != ')' && str[0][0]) {
        number = my_infin_add(number, \
        eval_expr1(str, my_infin_tol(str[0] + 1, str)));
    }
    return (number);
}

char    *eval_expr1(char **str, char *number)
{
    if (str[0][0] != '\0') {
        if (str[0][0] == '(')
            number = eval_expr1(str, my_prio_calc(number, str));
        if (str[0][0] == '*')
            number = my_infin_mult(number, \
            eval_expr1(str, my_infin_tol(str[0] + 1, str)));
        if (str[0][0] == '/')
            number = my_infin_div(number, \
            eval_expr1(str, my_infin_tol(str[0] + 1, str)));
        if (str[0][0] == '+')
            number = my_infin_add(number, \
            eval_expr1(str, my_infin_tol(str[0] + 1, str)));
        if (str[0][0] == '-')
            number = my_infin_add_neg(number, \
            eval_expr1(str, my_infin_tol(str[0] + 1, str)));
        if (str[0][0] == '%')
            number = my_infin_mod(number, \
            eval_expr1(str, my_infin_tol(str[0] + 1, str)));
    }
    return (number);
}