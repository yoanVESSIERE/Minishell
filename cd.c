/*
** EPITECH PROJECT, 2019
** cd.c
** File description:
** 
*/
#include "my.h"

void cd_command(char *buff, char *env[])
{
    int i = 0;
    int e = 0;
    char *path = NULL;

    env[0] = env[0];
    for (i = 0; buff[i] == '\0'; i++);
    path = malloc(sizeof(char) * (i + 1));
    for (i = 0; buff[i] == ' '; i++);
    for (; buff[i] != ' '; i++);
    for (; buff[i] == ' '; i++);
    if (buff[i] >= 33 && buff[i] <= 126) {
        for (e = 0; buff[i + 1] != '\0'; i++, e++)
            path[e] = buff[i];
        go_to_path(env, path);
        change_dir(path);
    }
    else {
        return_home(env);
        change_dir("..");
    }
}

int str_comp_cd(char *buff, char **env)
{
    int i = 0;
    int e = 0;
    int p = 0;
    char *cd = "cd";

    for (i = 0; buff[i] == ' '; i++);
    for (e = 0; buff[i] != '\0'; i++, p++) {
        if (buff[i] == cd[p]) {
            e++;
        }
    }
    if (e == 2 || e == 3)
        cd_command(buff, env);
    return (0);
}