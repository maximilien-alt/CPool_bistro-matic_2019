/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** infin_sub.c
*/

#include "include/my.h"
#include <stdlib.h>

char *my_calc_sub(char *str, char *cpy, char *result)
{
    int str_len = my_strlen(str) - 1;
    int cursor = 0;
    char digit = '0';

    while (str_len > 0) {
        digit = (str[cursor] - cpy[cursor]) + '0';
        if (digit >= '0') {
            result[cursor] = digit;
        } else {
            result[cursor] = (((str[cursor] + 10)- cpy[cursor]) + '0');
            cpy[cursor + 1] += 1;
        }
        cursor += 1;
        str_len += -1;
    }
    if ((str[cursor] - cpy[cursor] + '0') >= '0') {
        result[cursor] = str[cursor] - cpy[cursor] + '0';
    } else {
        result[cursor] = '0';
    }
    result[cursor + 1] = '\0';
    my_revstr(result);
    return (result);
}

char *create_my_sub(char *str, char *str2, char *result)
{
    char *cpy;
    int digit = 0;

    cpy = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str2[digit]) {
        cpy[digit] = str2[digit];
        digit += 1;
    }
    while (str[digit]) {
        cpy[digit] = '0';
        digit += 1;
    }
    cpy[digit] = '\0';
    return (my_calc_sub(my_revstr(str), cpy, result));
}

char *my_infin_sub(char *str, char *str2)
{
    char *result;
    char *str_new = my_delete_neg(my_str_delete_null(str));
    char *str2_new = my_delete_neg(my_str_delete_null(str2));
    char *cpy;

    if (my_infin_cmp(str_new, str2_new) == 1) {
        result = malloc(sizeof(char) * (my_strlen(str_new) + 2));
        str2 = my_revstr(str2_new);
        create_my_sub(str_new, str2, result);
        result = my_str_delete_null(result);
        return (result);
    } else {
        result = malloc(sizeof(char) * (my_strlen(str2_new) + 3));
        result[0] = '-';
        str = my_revstr(str_new);
        create_my_sub(str2_new, str, &result[1]);
        result = my_str_delete_null(result);
        return (&result[0]);
    }
}