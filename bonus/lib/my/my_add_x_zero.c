/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** my_add_x_zero.c
*/

char    *my_add_x_zero(char *str, int x, int cursor)
{
    while (x > 0) {
        str[cursor] = '0';
        cursor += 1;
        x += -1;
    }
    return (str);
}