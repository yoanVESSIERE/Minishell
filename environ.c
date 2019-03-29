/*
** EPITECH PROJECT, 2019
** environ.c
** File description:
** 
*/
#include "my.h"

void unset_envir(char **env, char *buff)
{
    int i = 0;
    int a = 0;
    int e = 0;
    int p = 0;
    int cpy = 0;

    for (i = 0; buff[i] == ' '; i++);
    for (; buff[i] != ' '; i++);
    for (; buff[i] == ' '; i++);
    for (p = i; buff[p + 1] != '\0'; p++);
    p = p - i;
    for (e = 0; env[e] != NULL; e++) {
        cpy = i;
        for (a = 0; env[e][a] == buff[cpy]; cpy++, a++);
        if (a == p) {
            for(; env[e + 1] != NULL; e++)
                env[e] = env[e + 1];
        }
    }
    env[e - 1] = NULL;
}

void set_envir(char **env, char *buff)
{
    int i = 0;
    int c = 0;
    int e = 0;
    int a = 0;

    for (a = 0; env[a] != NULL; a++);
    for (i = 0; buff[i] == ' '; i++);
    for (; buff[i] != ' '; i++);
    for (; buff[i] == ' '; i++);
    for (c = i; buff[c] != ' '; c++);
    env[a] = malloc(sizeof(char *) * (c * 2));
    env[a + 1] = NULL;
    for (e = 0; buff[i] != '\n' && buff[i] != ' '; i++, e++) {
        env[a][e] = buff[i];
    }
    env[a][e] = '=';
    for (; buff[i] == ' '; i++);
    e++;
    for (; buff[i] != '\n'; i++, e++)
        env[a][e] = buff[i];
}