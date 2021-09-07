/*
** EPITECH PROJECT, 2021
** gestion funcs for shell
** File description:
** gestion
*/

#include "my.h"
#include "shell.h"

flags_t *init_flags(void)
{
    flags_t *flagsredirect = malloc(sizeof(flags_t) * 5);

    flagsredirect[0] = (flags_t){"cd", &my_cd};
    flagsredirect[1] = (flags_t){"exit", &my_exit};
    flagsredirect[2] = (flags_t){"env", &my_env};
    flagsredirect[3] = (flags_t){"setenv", &my_setenv};
    flagsredirect[4] = (flags_t){"unsetenv", &my_unsetenv};
    return flagsredirect;
}

bool does_exist(char *path)
{
    if (access(path, F_OK) != -1)
        return true;
        else
            return false;
}

bool can_access(char *path)
{
    if (access(path, X_OK) != -1)
        return true;
        else
            return false;
}

int resolve_cmd(list_t *lenv, char **args)
{
    if (does_exist(args[0]) == false) {
        my_printf("%s: command not found.\n", args[0]);
        return 1;
    }
    else if (can_access(args[0]) == true)
        return run(lenv, args, args[0]);
        else {
            my_printf("%s: Permission denied.", args[0]);
            return 1;
        }
}

int get_cmd(list_t **lenv, flags_t *flags, char **args)
{
    int status = 0;

    for (int i = 0; i < 5; i++) {
        if (my_strcmp(args[0], flags[i].flag) == 0) {
            status = flags[i].redirect(lenv, args);
            unalloc_tab(args);
            return status;
        }
    }
    if ((status = resolve_path(*lenv, args)) == -1)
        status = resolve_cmd(*lenv, args);
    unalloc_tab(args);
    return status;
}