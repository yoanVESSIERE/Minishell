/*
** EPITECH PROJECT, 2019
** main;c
** File description:
** 
*/
#include "my.h"

void execute(char *path, char *env[], char *rep[])
{
    char *newenv[] = {NULL};
    pid_t pid = 0;

    for (int i = 0; newenv[i] != NULL; i++)
        newenv[i] = newenv[i];
    pid = fork();
    if (pid == 0) {
        execve(path, rep, env);
    }
    else {
        waitpid(pid, 0, 0);
        kill(pid, SIGTERM);
    }
}

void repository(char *buff, char *rep[])
{
    int i = 0;
    int e = 0;
    int a = 0;
    int p = 1;
    int z = 0;

    for (i = 0; buff[i] == ' '; i++);
    for (e = 0; buff[i] != ' ' && buff[i] != '\n'; i++, e++)
        rep[0][e] = buff[i];
    for (a = e, p = 1; buff[a] != '\0'; a++, p++) {
        for (; buff[i] == ' '; i++);
        for (e = 0; buff[i] != '\n' && buff[i] != ' '; i++, e++) {
            rep[p][e] = buff[i];
            z++;
        }
    }
    if (z == 0)
        rep[1] = NULL;
    else
        rep[2] = NULL;
}

int search(char *cpy, char *buff, char **env)
{
    int i = 0;
    int e = 0;
    char *path = NULL;
    char **rep;

    for (i = 0; cpy[i] != '\0'; i++);
    for (e = 0; buff[e] != '\0'; e++, i++);
    path = malloc(sizeof(char) * (i + 1));
    rep = malloc(sizeof(char *) * (i + 1));
    for (e = 0; e != i; e++)
        rep[e] = malloc(sizeof(char) * (i + 1));
    path = strcate(cpy, buff, path);
    i = access(path, F_OK);
    if (i == 0) {
        repository(buff, rep);
        execute(path, env, rep);
        return (1);
    }
    return (0);
}

int in_file(char *str, char *buff, char **env)
{
    int i = 0;
    int e = 0;
    int a = 0;
    char *cpy = NULL;

    cpy = malloc(sizeof(char) * 500);
    for (; str[e] != '\0'; e++) {
        for (i = 0; str[e] != ':'; e++, i++) {
            cpy[i] = str[e];
            if (str[e] == '\0')
                break;
        }
        if ((a = search(cpy, buff, env)) == 1)
            break;
        for (int o = 0; cpy[o] != '\0'; cpy[o] = '\0', o++);
    }
    return (0);
}

int check_env(char **env, char *buff)
{
    int i = 0;
    int e = 0;
    char *str = NULL;

    str = malloc(sizeof(char) * 500);
    for (; env[e] != NULL; e++)
        if (env[e][i] == 'P' && env[e][i + 1] == 'A' && env[e][i + 2] == 'T') {
            str = my_strcpy(str, env[e]);
        }
    for (i = 0; str[i + 5] != '\0'; i++)
        str[i] = str[i + 5];
    str[i] = '\0';
    in_file(str, buff, env);
    return (0);
}

int main(int ac, char *av[], char **env)
{
    char *buff = NULL;
    size_t size = 100;
    int o = 0;

    ac = ac;
    av[0] = av[0];
    while (1) {
        my_putstr("$>");
        o = getline(&buff, &size, stdin);
        if (o == -1)
            exit(0);
        str_comp_all(buff, env);
    }
    return (0);
}