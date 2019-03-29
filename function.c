/*
** EPITECH PROJECT, 2019
** function.c
** File description:
** 
*/
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    if (nb < 0 && (nb * -1) > 9) {
        my_putchar(45);
        nb = nb * -1;
        my_put_nbr(nb / 10);
    }
    else if (nb < 0) {
        my_putchar(45);
        nb = nb * -1;
    }
    my_putchar(nb % 10 + '0');
    return (0);
}

char *strcate(char *cpy, char *buff, char *path)
{
    int i = 0;
    int e = 0;

    for (i = 0; cpy[i] != '\0'; i++);
    for (e = 0; buff[e] == ' '; e++);
    for (; buff[e] != '\0'; e++, i++);
    path = malloc(sizeof(char) * (i + 1));
    for (i = 0; cpy[i] != '\0'; i++)
        path[i] = cpy[i];
    path[i] = '/';
    i++;
    for (e = 0; buff[e] == ' '; e++);
    for (; buff[e - 1] != '\n' && buff[e - 1] != ' '; e++, i++)
        path[i] = buff[e];
    path[i - 1] = '\0';
    return (path);
}

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}