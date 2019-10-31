/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** main.c
*/

#include "include/my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *eval_expr(char *str);

char    *my_condition(char *buff, char *operators, int cursor)
{
    if (buff[cursor] == operators[0])
        buff[cursor] = '(';
    if (buff[cursor] == operators[1])
        buff[cursor] = ')';
    if (buff[cursor] == operators[2])
        buff[cursor] = '+';
    if (buff[cursor] == operators[3])
        buff[cursor] = '-';
    if (buff[cursor] == operators[4])
        buff[cursor] = '*';
    if (buff[cursor] == operators[5])
        buff[cursor] = '/';
    if (buff[cursor] == operators[6])
        buff[cursor] = '%';
}

char    *my_new_buffer(char *buff, char *operators)
{
    int cursor = 0;

    while (buff[cursor]) {
        my_condition(buff, operators, cursor);
        cursor += 1;
    }
    return (buff);
}

int my_h(void)
{
    my_putstr("USAGE\n./calc base operators size_read\n\
\nDESCRIPTION\n- base: all the symbols of the base\
\n- operators: the symbols for the parentheses and the 5 operators\
\n- size_read: number of characters to be read\n");
    return (0);
}

int    bistro_main(int ac, char **av, int size, char *result)
{
    char buff[size + 1];

    if ((av[1][0] == '-' && av[1][1] == 'h') && ac == 2) {
        my_h();
        return (0);
    }
    read(0, buff, size + 1);
    buff[size] = '\0';
    if (my_bistro_error(ac, av, buff) == 0) {
        write(2, "syntax error", 13);
        return (0);
    }
    my_new_buffer(buff, av[2]);
    result = eval_expr(buff);
    if (my_strcmp(result, "error") == 0) {
        write(2, "syntax error", 13);
        return (0);
    }
    my_putstr(result);
    free (result);
    return (0);
}

int    main(int ac, char **av)
{
    int size = 0;
    char *result;

    if (ac != 4 && ac != 2) {
        write(2, "syntax error", 13);
        return (0);
    }
    size = my_getnbr(av[3]);
    bistro_main(ac, av, size, result);
    return (0);
}