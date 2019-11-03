/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** infin_multi.c
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *my_add_final(char *add_total, char *str, char *mult)
{
    char **tab_final;
    int cursor = 0;

    tab_final = my_str_to_word_array(add_total);
    add_total[0] = '\0';
    while (tab_final[cursor]) {
        add_total = my_infin_add(add_total, tab_final[cursor]);
        cursor += 1;
    }
    if ((str[0] == '-' && mult[0] == '-') || (str[0] != '-' && mult[0] != '-'))
        return (add_total);
    my_revstr(add_total);
    add_total = my_strcat(add_total, "-");
    my_revstr(add_total);
    return (my_str_delete_null(add_total));
}

char    *my_result1(char *result, int ret, int cursor, int c)
{
    if (c >= 10) {
        result[cursor] = (c % 10) + '0';
        result[cursor + 1] = (c / 10) + '0';
        result[cursor + 2] = '\0';
    } else {
        result[cursor] = c + '0';
        result[cursor + 1] = '\0';
    }
    return (result);
}

char    *my_mult_is_hard(char *str, char mult)
{
    char *result;
    int ret = 0;
    int cursor = 0;
    int c = 0;

    result = malloc(sizeof(char) * my_strlen(str) + 2);
    while (str[cursor + 1] != '\0') {
        c = ((str[cursor] - '0') * (mult - '0') + ret);
        if (c < 10) {
            result[cursor] = c + '0';
            ret = 0;
        } else {
            result[cursor] = (c % 10) + '0';
            ret = (c / 10);
        }
        cursor += 1;
    }
    c = ((str[cursor] - '0') * (mult - '0') + ret);
    result = my_result1(result, ret, cursor, c);
    return (my_revstr(result));
}

char *my_multi(char *str, char *mult, char *add_total, int cursor)
{
    char *line = my_mult_is_hard(str, mult[0]);

    add_total = my_strcat(add_total, line);
    add_total = my_strcat(add_total, my_add_x_zero(cursor));
    mult++;
    if (*mult) {
        add_total = my_strcat(add_total, " ");
        return (my_multi(str, mult, add_total, cursor + 1));
    } else {
        return (add_total);
    }
}

char *my_infin_mult(char *str, char *mult)
{
    char *add_total;
    char *str_n = my_delete_neg(str);
    char *mult_n = my_delete_neg(mult);

    if (my_infin_cmp(str, mult) == 1) {
        add_total = malloc(sizeof(char) * my_clean_add_total(str_n, mult_n));
        add_total[0] = '\0';
        add_total = my_multi(my_revstr(str_n), my_revstr(mult_n), add_total, 0);
    } else {
        add_total = malloc(sizeof(char) * my_clean_add_total(mult_n, str_n));
        add_total[0] = '\0';
        add_total = my_multi(my_revstr(mult_n), my_revstr(str_n), add_total, 0);
    }
    return (my_add_final(add_total, str, mult));
}