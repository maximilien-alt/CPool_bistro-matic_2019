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

int    bistro_main(char *buff, char **av, int size, char *result)
{
    int ac = 1;

    for (int icr = 1; av[icr] != NULL; icr += 1) {
        if (av[icr][0] != 0 && av[icr][0] != '\n')
            ac += 1;
    }
    if (my_bistro_error(ac, av, buff) == 0) {
        write(2, "syntax error\n", 14);
        return (0);
    }
    my_new_buffer(buff, av[2]);
    result = eval_expr(buff);
    if (my_strcmp(result, "error") == 0) {
        write(2, "syntax error\n", 14);
        return (0);
    }
    my_print_result(result);
    return (0);
}

int continue_of_main(char **av, char *tempo, char *buff, char *result)
{
    int base = 0;
    int size;

    my_putstr("Please enter your operation size\n");
    read(0, av[3], 10);
    size = my_getnbr(av[3]);
    buff = malloc(sizeof(char) * size + 1);
    my_putstr("Please enter your operation\n");
    read(0, buff, size + 1);
    buff[size] = 0;
    my_putstr("Please enter your base size\n");
    read(0, tempo, 9);
    base = my_getnbr(tempo);
    av[1] = malloc(sizeof(char) * base + 1);
    my_putstr("Now enter your base\n");
    read(0, av[1], base + 1);
    my_putstr("Finally enter your operator base\n");
    read(0, av[2], 8);
    bistro_main(buff, av, size, result);
}

int    main(void)
{
    char tempo[9];
    char *result;
    char **av;
    char *buff;
    char test[2];

    av = malloc(sizeof(char *) * 4);
    av[2] = malloc(sizeof(char) * 8);
    av[3] = malloc(sizeof(char) * 10);
    my_putstr("If you want to read the man press 0");
    my_putstr(" and if you want to use the calculator press 1\n");
    read(0, test, 2);
    if (test[0] == '1')
        continue_of_main(av, tempo, buff, result);
    if (test[0] == '0')
        my_putstr("USAGE\n./calc base operators size_read\n\
        \nDESCRIPTION\n- base: all the symbols of the base\
        \n- operators: the symbols for the parentheses and the 5 operators\
        \n- size_read: number of characters to be read\n");
    return (0);
}