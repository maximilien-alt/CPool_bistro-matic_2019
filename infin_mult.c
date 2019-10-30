/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** multiplies
*/

#include "include.h"

char *add_x_zero(char *a, int x)
{
    for (int icr = my_strlen(a); x > 0; x -= 1, icr += 1)
        a[icr] = '0';
    return a;
}

char *clean(char *buff)
{
    int limit = my_strlen(buff);
    for (int icr = 0; icr < limit; icr += 1)
        buff[icr] = 0;
    return (buff);
}

char *multiply(char *a, char *b, char *tempo, int hold)
{
    char *result;
    result = malloc(sizeof(char *) * (my_strlen(a) * my_strlen(b)));
    for (int icr = 0; a[icr] != '\0'; icr += 1)
    {
        result[0] = (a[icr] - '0') * (*b - '0');
        if (result[0] >= 10) {
            result[1] = (result[0] % 10) + '0';
            result[0] = (result[0] / 10) + '0';
        }
        else
            result[0] = result[0] + '0';
        add_x_zero(result, icr + hold);
        tempo = my_infin_add(result, tempo);
        clean(result);
    }
    if (*(b + 1) != '\0')
    tempo = multiply(a, b + 1, tempo, hold + 1);
    else
        return tempo;
}

int main (int ac, char **av)
{
    char *result;
    result = malloc(sizeof(char *) * (my_strlen(av[2]) + my_strlen(av[1]) + 2));
    result[0] = '0';
    result = multiply(my_revstr(av[1]), my_revstr(av[2]), result, 0);
    my_putstr(result);
    my_putchar('\n');
    free (result);
}