/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** infin_mod.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

char    *my_print_neg1(char *str)
{
    int letter = 0;
    int cursor = 0;
    char *res;

    res = malloc(sizeof(char) * my_strlen(str) + 1);
    res[letter] = '-';
    letter += 1;
    while (str[cursor]) {
        res[letter] = str[cursor];
        cursor += 1;
        letter += 1;
    }
    res[letter] = '\0';
    return (res);
}

char    *my_recursive1(char *str, char *div, char *result, int cursor)
{
    int var_result = 0;
    char *str_temp = my_strtemp(str, div);
    char *check = my_infin_add_neg(str_temp, div);
    char *rev_div = my_print_neg1(my_revstr(div));

    while (check[0] != '-') {
        var_result += 1;
        check = my_infin_add_neg(rev_div, check);
    }
    result[cursor] = var_result + '0';
    check = my_infin_add_neg(check, div);
    str = my_strcat(check, my_supr_same(str, str_temp));
    if (my_infin_cmp(div, str) == 0) {
        return (my_recursive1(str, div, result, cursor + 1));
    } else {
    if (str[0] == '0' && str[1] != '\0') {
            result[cursor + 1] = str[0];
            result[cursor + 2] = '\0';
        } else
        result[cursor + 1] = '\0';
    return (check);
    }
}

char    *my_infin_mod(char *str, char *div)
{
    char *result;

    if (str[0] == '-' && div[0] == '-') {
        str = my_delete_neg(str);
        div = my_delete_neg(div);
    }
    if (str[0] == '-' || div[0] == '-') {
        my_putchar('-');
        str = my_delete_neg(str);
        div = my_delete_neg(div);
    }
    if (div[0] == '0') {
        result = "syntax error";
        return (result);
    }
    if (my_infin_cmp(str, div) == 1) {
        result = malloc(sizeof(char) * my_strlen(str));
        result = my_recursive1(str, div, result, 0);
        return (result);
    } else
        return (str);
}