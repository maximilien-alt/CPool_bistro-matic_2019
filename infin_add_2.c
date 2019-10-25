/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** infin_add_2.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char    *my_disp_neg(char *result, int letter, int neg)
{
    if (neg == 1) {
        result[letter] = '-';
        result[letter + 1] = '\0';
    } else {
        result[letter] = '\0';
    }
    return (result);
}

char    *my_delete_neg(char *str)
{
    int letter = 0;
    int str_len = my_strlen(str);
    char *cpy;
    int i = 0;

    if (str[letter] == '-') {
        cpy = malloc(sizeof(char) * str_len);
        letter += 1;
    } else {
        return (str);
    }
    while (str[letter]) {
        cpy[i] = str[letter];
        letter += 1;
        i += 1;
    }
    cpy[i] = '\0';
    return (cpy);
}

char    *my_calc_str_neg(char *str, char *cpy, char *result, int neg)
{
    int str_len = my_strlen(str) - 1;
    int letter = 0;

    while (str_len > 0) {
        if ((str[str_len] - cpy[str_len] + '0') >= '0') {
            result[letter] = str[str_len] - cpy[str_len] + '0';
        } else {
            result[letter] = (((str[str_len] + 10)- cpy[str_len]) + '0');
            cpy[str_len - 1] += 1;
        }
        letter += 1;
        str_len += -1;
    }
    if ((str[str_len] - cpy[str_len] + '0') >= '0') {
        result[letter] = str[str_len] - cpy[str_len] + '0';
    } else {
        result[letter] = '0';
    }
    my_disp_neg(result, letter + 1, neg);
    return (my_revstr(result));
}

char    *create_my_cpy_neg(char *str, char *cpy, char *result, char *str2)
{
    int letter = 0;
    int neg = 0;

    if (str2[0] == '-')
        neg = 1;
    str2 = my_delete_neg(str2);
    while (str[letter]) {
        cpy[letter] = str[letter];
        letter += 1;
    }
    while (str2[letter]) {
        cpy[letter] = '0';
        letter += 1;
    }
    cpy[letter] = '\0';
    my_revstr(cpy);
    return (my_calc_str_neg(str2, cpy, result, neg));
}

char    *my_infin_add_neg(char *str, char *str2)
{
    int str_len = my_strlen(my_delete_neg(str));
    int str_len2 = my_strlen(my_delete_neg(str2));
    char *result;
    char *cpy;

    if (str_len > str_len2) {
        cpy = malloc(sizeof(char) * (str_len + 1));
        result = malloc(sizeof(char) * (str_len + 3));
        str2 = my_delete_neg(str2);
        my_revstr(str2);
        cpy = create_my_cpy_neg(str2, cpy, result, str);
        return (my_str_delete_null(result));
    } else {
        cpy = malloc(sizeof(char) * (str_len2 + 1));
        result = malloc(sizeof(char) * (str_len2 + 3));
        str = my_delete_neg(str);
        my_revstr(str);
        cpy = create_my_cpy_neg(str, cpy, result, str2);
        return (my_str_delete_null(result));
    }
}