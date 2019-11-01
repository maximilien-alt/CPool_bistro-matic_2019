/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include <stdlib.h>
#include <unistd.h>

int my_strlen(char *str);

char     *my_strcat(char *dest, char *src)
{
    int i = 0;
    int a = 0;
    char *cpy;

    if (src == NULL)
        return (dest);
    cpy = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    cpy[0] = '\0';
    while (dest[i]) {
        cpy[i] = dest[i];
        i += 1;
    }
    while (src[a]) {
        cpy[i] = src[a];
        a += 1;
        i += 1;
    }
    cpy[i] = '\0';
    return (cpy);
}
