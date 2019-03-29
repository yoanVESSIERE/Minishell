/*
** EPITECH PROJECT, 2019
** str_comp.c
** File description:
** 
*/
#include "my.h"

void str_comp_bin(char *buff, char *env[])
{
    char *newar[] = {"."};
    char *newenv[] = {NULL};
    pid_t pid = 0;
    int i = 0;
    char *path = NULL;

    path = malloc(sizeof(char) * 100);
    for(i = 0; buff[i] == ' '; i++)
    env[0] = env[0];
    for (int e = 0; buff[i] != '\n'; i++, e++)
        path[e] = buff[i];
    for (int i = 0; newenv[i] != NULL; i++)
        newenv[i] = newenv[i];
    pid = fork();
    if (pid == 0) {
        execve(path, newar, env);
        exit(0);
    }
    else {
        waitpid(pid, 0, 0);
        kill(pid, SIGTERM);
    }
}

int str_comp_unsetenv(char *buff, char **env)
{
    int i = 0;
    int e = 0;
    int p = 0;
    char *unsetenv = "unsetenv";

    for (i = 0; buff[i] == ' '; i++);
    for (e = 0; buff[i] != '\0'; i++, p++) {
        if (buff[i] == unsetenv[p])
            e++;
    }
    if (e == 9 || e == 8)
        unset_envir(env, buff);
    return (0);
}

int str_comp_setenv(char *buff, char **env)
{
    int i = 0;
    int e = 0;
    int p = 0;
    char *setenv = "setenv";

    for (i = 0; buff[i] == ' '; i++);
    for (e = 0; buff[i] != '\0'; i++, p++) {
        if (buff[i] == setenv[p])
            e++;
    }
    if (e == 6)
        set_envir(env, buff);
    return (0);
}

int str_comp_exit(char *buff)
{
    int i = 0;
    int e = 0;
    int p = 0;
    char *exi = "exit";

    for (i = 0; buff[i] == ' '; i++);
    for (e = 0; buff[i] != '\0'; i++, p++) {
        if (buff[i] == exi[p]) {
            e++;
        }
    }
    if (e == 4)
        exit(0);
    return (0);
}

int str_comp_all(char *buff, char **env)
{
    check_env(env, buff);
    str_comp_exit(buff);
    str_comp_bin(buff, env);
    str_comp_cd(buff, env);
    str_comp_setenv(buff, env);
    str_comp_unsetenv(buff, env);
    return (0);
}