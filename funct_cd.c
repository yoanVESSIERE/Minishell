/*
** EPITECH PROJECT, 2019
** funct_cd.c
** File description:
** 
*/
#include "my.h"

void change_dir(char *path)
{
    chdir(path);
}

void home(char *env[], int e, int i)
{
    for (e = 0; env[i][e] != '\0'; e++);
    for (; env[i][e - 1] != '/'; e--)
        env[i][e] = '\0';
}

void return_home(char *env[])
{
    int i = 0;
    int e = 0;

    for (i = 0; env[i] != NULL; i++)
        if (env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D')
            home(env, e, i);
}

void replace(char *env[], char *path, int i, int e)
{
    int t = 0;

    for (e = 0; env[i][e] != '\0'; e++);
    for (; env[i][e] != '/'; e--);
    e++;
    for (t = 0; env[i][e] != '\0'; e++, t++)
        env[i][e] = path[t];
}

void go_to_path(char *env[], char *path)
{
    int i = 0;
    int e = 0;

    for (i = 0; env[i] != NULL; i++)
        if (env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D')
            replace(env, path, i, e);
}