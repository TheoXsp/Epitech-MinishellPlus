/*
** EPITECH PROJECT, 2021
** path handling funcs
** File description:
** path_handling
*/

#include "my.h"
#include "shell.h"

void string_assembly(char *str, char *path, char *piece)
{
    my_strcpy(str, path);
    my_strcat(str, "/");
    my_strcat(str, piece);
}

char *reset_string(char *str)
{
    free(str);
    str = NULL;
    return str;
}

bool can_it_run(char *path)
{
    if (access(path, F_OK) != -1 && access(path, X_OK) != -1)
        return true;
        else
            return false;
}

int resolve_path(list_t *lenv, char **args)
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
            status = run(lenv, args, str);
            reset_string(str);
            break;
        }
        str = reset_string(str);
    }
    free(path);
    unalloc_tab(paths);
    return status;
}