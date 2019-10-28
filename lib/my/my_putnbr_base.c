/*
** EPITECH PROJECT, 2019
** my_putnbr_base.c
** File description:
** 
*/

void    my_putchar(char c);
int    my_strlen(char const *str);

int    my_putnbr_base(int nbr, char const *base)
{
    int len = my_strlen(base);

    if (nbr >= len) {
        my_putnbr_base(nbr / len, base);
    }
    nbr = nbr % len;
    my_putchar(base[nbr]);
}
