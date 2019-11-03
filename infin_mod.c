/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** infin_div.c
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>

char *my_infin_sub(char *str, char *str2);

char *my_infin_mult(char *str, char *mult);

char *my_infin_div(char *str, char *div);

char *my_mod_res(char *result, char *div, char *str)
{
    if (div[0] == '-' && str[0] == '-') {
        return (my_str_delete_null(result));
    }
    if (div[0] == '-' || str[0] == '-') {
        my_revstr(result);
        result = my_strcat(result, "-");
        my_revstr(result);
    }
    return (my_str_delete_null(result));

}

char *my_infin_mod(char *str, char *div)
{
    char *result;
    char *str_new = my_delete_neg(my_str_delete_null(str));
    char *div_new = my_delete_neg(my_str_delete_null(div));
    char *div2;
    char *mult;

    if (div_new[0] == '0')
        return ("error");
    if (my_infin_cmp(str_new, div_new) == 1) {
        div2 = my_infin_div(str_new, div_new);
        my_revstr(str_new);
        my_revstr(div_new);
        mult = my_infin_mult(div2, div_new);
        my_revstr(str_new);
        my_revstr(div_new);
        result = my_infin_sub(str_new, mult);
    } else {
        return (str);
    }
    return (my_mod_res(result, div, str));
}