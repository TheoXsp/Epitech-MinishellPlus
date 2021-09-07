/*
** EPITECH PROJECT, 2021
** builins for the shell
** File description:
** builtins
*/

#include "my.h"
#include "shell.h"

int my_cd(list_t **env, char **args)
{
    char *path = NULL;
    int size = get_args_nbr(args);
    int status = 0;

    if (size == 1) {
        update_env_value(*env, "OLDPWD", getcwd(NULL, 0));
        path = get_env_value(*env, "HOME");
        chdir(path);
        free(path);
        return 0;
    }
    if ((status = check_cd_minus(*env, args, size)) == 2) {
        if (cd_err_check(*env, args) != 1) {
            update_env_value(*env, "OLDPWD", getcwd(NULL, 0));
            chdir(args[1]);
        }
        else
            return 1;
    }
    else if (status == 1) return 1;
    return 0;
}

int my_exit(list_t **env, char **args)
{
    int status = 0;
    int size = get_args_nbr(args);

    if (size == 1)
        exit(0);
    if (size > 2) {
        my_printf("exit: Expression Syntax.\n");
        return 1;
    }
    if (size == 2) {
        status = my_getnbr(args[1]);
        if (status <= 256) {
            my_printf("exit\n");
            exit(status);
        }
        else if (status > 256) {
            my_printf("exit\n");
            exit(status % 256);
        }
    }
}

int my_env(list_t **env, char **args)
{
    list_t *temp = *env;

    for (; temp != NULL; temp = temp->next)
        my_printf("%s=%s\n", temp->data->key, temp->data->value);
}

int my_setenv(list_t **env, char **args)
{
    int size = get_args_nbr(args);

    if (size == 1) {
        my_env(env, args);
        return 0;
    }
    if (size > 3) {
        my_printf("setenv: Too many arguments.\n");
        return 1;
    }
    if (size == 2)
        env_add(env, args[1], my_strdup("\0"));
    if (size == 3)
        env_add(env, args[1], args[2]);
    return 0;
}

int my_unsetenv(list_t **env, char **args)
{
    int size = get_args_nbr(args);

    if (size == 1)
        return 0;
    for (int i = 1; i != size; i++)
        list_remove_from_key(env, args[i]);
}