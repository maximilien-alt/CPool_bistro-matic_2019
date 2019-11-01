/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** infin_div.c
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>

char *my_return_is_easy(char *str, char *result, int cursor)
{
<<<<<<< HEAD
    if (str[0] == '0' && str[1] != '\0') {
        result[cursor + 1] = str[0];
        result[cursor + 2] = '\0';
    } else {
        result[cursor + 1] = '\0';
    }
    return (result);
}

char *my_recursive(char *str, char *div, char *result, int cursor)
=======
    char *error;

    if (a == 1) {
        error = malloc(sizeof(char) * 2);
        error[0] = '0';
        error[1] = '\0';
        return (error);
    }
}

char    *my_recursive(char *str, char *div, char *result, int cursor)
>>>>>>> 9c1c1c34c192bcc9f739d9168168081807c48071
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
    printf("%s\n", check);
    str = my_strcat(check, my_supr_same(str, str_temp));
    if (my_infin_cmp(div, str) == 0) {
        return (my_recursive(str, my_revstr(div), result, cursor + 1));
    } else {
        return (my_return_is_easy(str, result, cursor));
    }
}

char *my_infin_div(char *str, char *div)
{
    char *result;
    char *str_new = my_delete_neg(str);
    char *div_new = my_delete_neg(div);

    if (div[0] == '0') {
        result = "error";
        return (result);
    }
<<<<<<< HEAD
    if (my_infin_cmp(str_new, div_new) == 1) {
        if (str[0] == '-' || div[0] == '-') {
            result = malloc(sizeof(char) * (my_strlen(str)+ 2));
            result[0] = '-';
            result[1] = '\0';
            my_recursive(str_new, div_new, &result[1], 0);
        } else {
            result = malloc(sizeof(char) * (my_strlen(str)+ 1));
            result[0] = '\0';
            my_recursive(str, div, result, 0);
        }
    } else {
        result = "0";
    }
    return (&result[0]);
=======
    if (my_infin_cmp(my_delete_neg(str), my_delete_neg(div)) == 1) {
        result = malloc(sizeof(char) * my_strlen(str) + 1);
        tempo = malloc(sizeof(char) * my_strlen(str));
        result = my_zeroo(str, div);
        str = my_delete_neg(str);
        div = my_delete_neg(div);
        tempo = my_recursive(str, div, tempo, 0);
        my_strcat(result, tempo);
        result = my_str_delete_null(result);
        return (result);
    } else
        return (my_error_div(1));
}

int main(int ac, char *av[])
{
    char *res = my_infin_div(av[1], av[2]);
    printf("%s\n", res);
    free (res);
    return (0);
>>>>>>> 9c1c1c34c192bcc9f739d9168168081807c48071
}