/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include <unistd.h>

char     *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int a = 0;

    if (src == NULL)
        return (dest);
    while (dest[i] != '\0') {
        i++;
    }
    while (src[a] != '\0') {
        dest[i] = src[a];
        a++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
