/*
** EPITECH PROJECT, 2021
** special execs gestions
** File description:
** special_gestion
*/

#include "my.h"
#include "shell.h"

int resolve_redirect_path(list_t *lenv, char **args, char **sargs, bool append)
{
    char *path = get_env_value(lenv, "PATH");
    char **paths = str_to_arr(path, ':');
    char *str = NULL;
    int size = 0;
    int status = -1;

    for (int i = 0; paths[i] != NULL; i++) {
        size = (my_strlen(paths[i]) + my_strlen(args[0]) + 2);
        str = malloc(sizeof(char) * size);
        string_assembly(str, paths[i], args[0]);
        if (can_it_run(str) == true) {
            free(args[0]), args[0] = my_strdup(str);
            status = run_redirect(lenv, args, sargs, append);
            reset_string(str);
            break;
        }
        str = reset_string(str);
    }
    free(path);
    unalloc_tab(paths);
    return status;
}

int resolve_redirect_cmd(list_t *lenv, char **args, char **sargs, bool append)
{
    if (does_exist(args[0]) == false) {
        my_printf("%s: command not found.\n", args[0]);
        return 1;
    }
    else if (can_access(args[0]) == true)
        return run_redirect(lenv, args, sargs, append);
        else {
            my_printf("%s: Permission denied.", args[0]);
            return 1;
        }
}

int get_redirect_cmd(list_t **lenv, char **args, char **sargs, bool append)
{
    int status = 0;
    flags_t *flags = init_flags();

    for (int i = 0; i < 5; i++) {
        if (my_strcmp(args[0], flags[i].flag) == 0) {
            status = flags[i].redirect(lenv, args);
            unalloc_tab(args);
            return status;
        }
    }
    if ((status = resolve_redirect_path(*lenv, args, sargs, append)) == -1)
        status = resolve_redirect_cmd(*lenv, args, sargs, append);
    unalloc_tab(args);
    free(flags);
    return status;
}