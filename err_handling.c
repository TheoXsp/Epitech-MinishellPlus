/*
** EPITECH PROJECT, 2021
** some error handling funcs
** File description:
** err_handling
*/

#include "my.h"
#include "shell.h"

int cd_err_check(list_t *lenv, char **args)
{
    struct stat st;

    if (stat(args[1], &st) != 0) {
        my_printf("%s: No such file or directory.\n", args[1]);
        return 1;
    }
    if (S_ISREG(st.st_mode)) {
        my_printf("%s: Not a directory.\n", args[1]);
        return 1;
    }
    return 0;
}

int check_cd_minus(list_t *lenv, char **args, int size)
{
    char *path = get_env_value(lenv, "OLDPWD");

    if (size > 2) {
        my_printf("cd: Too many arguments.\n");
        return 1;
    }
    if (args[1][0] == '-' && args[1][1] == '\0') {
        update_env_value(lenv, "OLDPWD", getcwd(NULL, 0));
        chdir(path);
        free(path);
        return 0;
    }
    else if (args[1][0] == '-' && args[1][1] != '\0') {
        my_printf("Usage: cd [-plvn][-|<dir>].\n");
        free(path);
        return 1;
    }
    free(path);
    return 2;
}