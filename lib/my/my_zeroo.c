/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_zeroo.h
*/

#include <stdlib.h>

char    *my_zeroo(void)
{
    char *res;

    res = malloc(sizeof(char) * 2);
    res[0] = '0';
    res[1] = '\0';
    return (res);
}