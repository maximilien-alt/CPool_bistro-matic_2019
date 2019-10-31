/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** infin_mult.c
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

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
    char *add_final = my_zeroo();
    char *rev_str = my_revstr(str);
    char **tab_final;
    int cursor = 0;

    if (str_len > mult_len) {
        add_total = malloc(sizeof(char) * my_clean_add_total(str, mult));
        add_total = my_multiplication(rev_str, my_revstr(mult), add_total, 0);
    } else {
        add_total = malloc(sizeof(char) * my_clean_add_total(mult, str));
        add_total = my_multiplication(my_revstr(mult), rev_str, add_total, 0);
    }
    tab_final = my_str_to_word_array(add_total);
    while (tab_final[cursor] != NULL) {
        add_final = my_infin_add(add_final, tab_final[cursor]);
        cursor += 1;
    }
    return (add_final);
}

int    main(int ac, char *av[])
{
    char *res = my_infin_mult(av[1], av[2]);

    printf("resultat final = %s\n", res);
    return (0);
}