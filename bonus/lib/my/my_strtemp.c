/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_strtemp.c
*/

#include <stdlib.h>

int    my_infin_cmp(char *str, char *strtemp);

int    my_strlen(char const *str);

char    *my_strtemp(char *str, char *div)
{
    char *str_temp;
    int cursor = 0;

    str_temp = malloc(sizeof(char) * (my_strlen(str) + 1));
    str_temp[cursor] = str[cursor];
    cursor += 1;
    str_temp[cursor] = '\0';
    while (my_infin_cmp(str_temp, div) == 0) {
        str_temp[cursor] = str[cursor];
        cursor += 1;
        str_temp[cursor] = '\0';
    }
    return (str_temp);
}