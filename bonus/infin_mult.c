/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** infin_mult.c
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *final_add(char *res, char **tab, int test)
{
    int cursor = 0;
    int is_neg = test;
    char *tempo;

    tempo = malloc(sizeof(char) * (my_strlen(res) + 1));
    if (*res == '-') {
        tempo[0] = '-';
        tempo[1] = 0;
    }
    else {
        tempo[0] = 0;
    }
    res = res + is_neg;
    while (tab[cursor] != NULL) {
        res = my_infin_add(res, tab[cursor]);
        cursor += 1;
    }
    tempo = my_strcat(tempo, res);
    return (my_str_delete_null(tempo));
}

char    *my_result(char *result, int ret, int cursor, int c)
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

char    *my_mult_is_easy(char *str, char mult)
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
    result = my_result(result, ret, cursor, c);
    return (my_revstr(result));
}

char    *my_multiplication(char *str, char *mult, char *add_total, int nul)
{
    char *line = my_mult_is_easy(str, mult[0]);

    if (nul == 0)
        add_total[0] = 0;
    add_total = my_strcat(add_total, my_str_delete_null(line));
    add_total = my_add_x_zero(add_total, nul, my_strlen(add_total));
    mult = my_delete_mult(mult);
    if (mult[0]) {
        add_total[my_strlen(add_total)] = ' ';
        return (my_multiplication(str, mult, add_total, nul + 1));
    } else {
        add_total[my_strlen(add_total)] = '\0';
        return (add_total);
    }
}

char    *my_infin_mult(char *str, char *mult)
{
    int str_len = my_strlen(str);
    int mult_len = my_strlen(mult);
    char *add_total;
    char *add_final = my_zeroo(str, mult);
    str = my_delete_neg(str);
    mult = my_delete_neg(mult);
    char *rev_str = my_revstr(str);
    char **tab_final;
    int test = 0;

    if (str_len > mult_len) {
        add_total = malloc(sizeof(char) * my_clean_add_total(str, mult));
        add_total = my_multiplication(rev_str, my_revstr(mult), add_total, 0);
    } else {
        add_total = malloc(sizeof(char) * my_clean_add_total(mult, str));
        add_total = my_multiplication(my_revstr(mult), rev_str, add_total, 0);
    }
    tab_final = my_str_to_word_array(add_total);
    if (add_final[0] == '-')
        test = 1;
    return (final_add(add_final, tab_final, test));
}
