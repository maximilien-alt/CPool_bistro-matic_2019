/*
** EPITECH PROJECT, 2019
** bistro matic
** File description:
** prints a beautyful result
*/

int     my_putstr(char const *str);
void    my_putchar(char c);
int    my_strlen(char const *str);

void my_print_result(char *result)
{
    int len = my_strlen(result);

    my_putstr(" o");
    for (int icr = 0; icr < len + 13; icr += 1)
        my_putchar('-');
    my_putstr("o\n | ");
    my_putstr("The result = ");
    for (int icr = 0; icr < len - 2; icr += 1)
        my_putchar(' ');
    my_putstr(" | \n");
    my_putstr(" | ");
    for (int icr = 0; icr < 8; icr += 1)
        my_putchar(' ');
    my_putstr(result);
    for (int icr = 0; icr < 3; icr += 1)
        my_putchar(' ');
    my_putstr(" | \n o");
    for (int icr = 0; icr < len + 13; icr += 1)
        my_putchar('-');
    my_putstr("o\n");
}