/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** 
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int nb);

int str_comp_all(char *buff, char **env);

int check_env(char **env, char *buff);

int str_comp_exit(char *buff);

int str_comp_env(char *buff, char **envi);

int str_comp_setenv(char *buff, char **env);

int in_file(char *str, char *buff, char **env);

int search(char *cpy, char *buff, char **env);

void execute(char *path, char *env[], char *rep[]);

char *strcate(char *cpy, char *buff, char *path);

char *my_strcpy(char *dest, char const *src);

void envir(char **env);

void set_envir(char **env, char *buff);

void unset_envir(char **env, char *buff);

int str_comp_cd(char *buff, char **env);

void go_to_path(char *env[], char *path);

void return_home(char *env[]);

void change_dir(char *path);