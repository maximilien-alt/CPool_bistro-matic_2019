/*
** EPITECH PROJECT, 2019
** CPool_evalexpr_bootstrap_2019
** File description:
** summands.c
*/

int    my_strtol(char const *str, char **endptr);

int    summands(char **str, int number)
{
    number = my_strtol(str[0], str);
    while (str[0][0] != '\0') {
        if (str[0][0] == '-') {
            number = number - my_strtol(str[0] + 1, str);
        } else {
            number = number + my_strtol(str[0] + 1, str);
        }
    }
    return (number);
}
