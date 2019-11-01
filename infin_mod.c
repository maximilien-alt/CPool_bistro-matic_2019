/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** infin_div.c
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>

char *my_recursive1(char *str, char *div, char *result, int cursor)
{
    char *str_temp = my_strtemp(str, div);
    char *check = my_infin_sub(str_temp, div);
    int var_result = 0;

    my_revstr(str_temp);
    my_revstr(div);
    while (check[0] != '-') {
        check = my_infin_sub(check, div);
        my_revstr(div);
        var_result += 1;
    }
    result[cursor] = var_result + '0';
    result[cursor + 1] = '\0';
    check = my_infin_sub(div, my_delete_neg(check));
    str = my_strcat(check, my_supr_same(str, str_temp));
    if (my_infin_cmp(div, str) == 0) {
        return (my_recursive1(str, my_revstr(div), result, cursor + 1));
    } else {
        return (check);
    }
}

char *my_infin_mod(char *str, char *div)
{
    char *result;
    char *str_new = my_delete_neg(str);
    char *div_new = my_delete_neg(div);

    if (div[0] == '0') {
        result = "error";
        return (result);
    }
    if (my_infin_cmp(str_new, div_new) == 1) {
        if (str[0] == '-' || div[0] == '-') {
            result = malloc(sizeof(char) * (my_strlen(str)+ 2));
            result[0] = '-';
            result[1] = '\0';
            result = my_recursive1(str_new, div_new, &result[1], 0);
        } else {
            result = malloc(sizeof(char) * (my_strlen(str)+ 1));
            result[0] = '\0';
            result = my_recursive1(str, div, result, 0);
        }
    } else {
        result = (str);
    }
    return (&result[0]);
}